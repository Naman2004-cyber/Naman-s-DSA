class Solution {
public:
    long long dp[16][11][2][2];
    long long doit(int idx , int prevDigit , bool tight , bool started , string &str , int k){
        if(idx == str.size()) return started;
        if(dp[idx][prevDigit][tight][started] != -1) return dp[idx][prevDigit][tight][started];
        int limit = tight ? str[idx]-'0' : 9;
        long long ans = 0;
        for(int digit = 0 ; digit<=limit ; digit++){
            bool nextTight = tight && (digit == str[idx]-'0');
            bool nextStarted = started || (digit != 0);
            if(!nextStarted){
                ans+=doit(idx+1 , 10 , false , false , str , k);
            }
            else{
                if(!started || (abs(prevDigit - digit) <= k)){
                    ans+=doit(idx+1 , digit , nextTight , nextStarted , str , k);
                }
            }
        }
        return dp[idx][prevDigit][tight][started] = ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        string low = to_string(l-1);
        string high = to_string(r);
        memset(dp , -1 , sizeof(dp));
        long long first = doit(0 , 10 , true , false , low , k);
        memset(dp , -1 , sizeof(dp));
        long long second = doit(0 , 10 , true , false , high , k);
        return second - first;
    }
};