class Solution {
public:
    long long dp[20][11][2][2];
    long long doit(int pos , int prevDigit , bool tight , bool started , int k , string &str){
        if(pos == str.size()) return started == true;
        if(dp[pos][prevDigit][tight][started] != -1) return dp[pos][prevDigit][tight][started];
        int limit = tight ? str[pos]-'0' : 9;
        long long ans = 0;
        for(int digit = 0 ; digit<=limit ; digit++){
            bool nextTight = tight && (digit == str[pos]-'0');
            bool nextStarted = started || (digit != 0);
            if(!nextStarted){
                ans+=doit(pos+1 , 10 , nextTight , false , k , str);
            }
            else{
                if(!started || abs(prevDigit-digit) <= k){
                    ans+=doit(pos+1 , digit , nextTight , nextStarted , k , str);
                }
            }
        }
        return dp[pos][prevDigit][tight][started] = ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        string low = to_string(l-1);
        string high = to_string(r);
        memset(dp , -1 , sizeof(dp));
        long long first = doit(0 , 10 , true , false , k , low);
        memset(dp , -1 , sizeof(dp));
        long long second = doit(0 , 10 , true , false , k , high);
        long long ans = second - first;
        return ans;
    }
};