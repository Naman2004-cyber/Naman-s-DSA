class Solution {
public:
    int dp[11][11][11][20][2][2];
    int doit(int idx , int odd_count , int even_count , int rem , bool tight , bool started , string &str , int &k){
        if(idx == str.size()){
            if(started && (even_count == odd_count) && (rem == 0)) return 1;
            return 0;
        }
        if(dp[idx][odd_count][even_count][rem][tight][started] != -1) return dp[idx][odd_count][even_count][rem][tight][started];
        int limit = tight ? str[idx] -'0' : 9;
        int ans = 0;
        for(int digit = 0 ; digit <= limit ; digit++){
            bool nextStarted = started || (digit != 0);
            bool nextTight = tight && (digit == limit);
            if(!nextStarted){
                ans+=doit(idx+1 , odd_count , even_count , rem , nextTight , false , str , k);
            }
            else{
                int next_odd_count = odd_count;
                int next_even_count = even_count;
                if(digit%2 == 0){
                    next_even_count++;
                }
                else{
                    next_odd_count++;
                }
                int next_rem = (rem*10 + digit)%k;
                ans+=doit(idx+1 , next_odd_count , next_even_count , next_rem , nextTight , nextStarted , str , k);
            }
        }
        return dp[idx][odd_count][even_count][rem][tight][started] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string useLow = to_string(low-1);
        string useHigh = to_string(high);
        memset(dp , -1 , sizeof(dp));
        int first = doit(0 , 0 , 0 , 0 , true , false , useLow , k);
        memset(dp , -1 , sizeof(dp));
        int second = doit(0 , 0 , 0 , 0 , true , false , useHigh , k);
        int ans = second - first;
        return ans;
    }
};