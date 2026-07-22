class Solution {
public:
    int dp[10][1024][2][2];
    int doit(int idx , int mask , bool tight , bool started , string &str){
        if(idx == str.size()) return started;
        if(dp[idx][mask][tight][started] != -1) return dp[idx][mask][tight][started];
        int limit = tight ? str[idx]-'0' : 9;
        int ans = 0;
        for(int digit = 0 ; digit<=limit ; digit++){
            bool nextTight = tight && (digit == limit);
            bool nextStarted = started || (digit != 0);
            if(!nextStarted){
                ans+=doit(idx+1 , mask , nextTight , false , str);
            }
            else{
                if(mask & (1 << digit)) continue;
                int nextMask = mask | (1 << digit);
                ans+=doit(idx+1 , nextMask , nextTight , nextStarted , str);
            }
        }
        return dp[idx][mask][tight][started] = ans;
    }
    int numDupDigitsAtMostN(int n) {
        string str = to_string(n);
        memset(dp , -1 , sizeof(dp));
        int finalans = doit(0 , 0 , true , false , str);
        return n - finalans;
    }
};