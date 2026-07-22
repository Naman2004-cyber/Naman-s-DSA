class Solution {
public:
    int dp[11][1024][2][2];
    int doit(int idx , int mask , bool tight , bool started , string &str){
        if(idx == str.size()) return started;
        if(dp[idx][mask][tight][started] != -1) return dp[idx][mask][tight][started];
        int limit = tight ? str[idx]-'0' : 9;
        int ans = 0;
        for(int digit = 0 ; digit<=limit ; digit++){
            int nextStarted = started || (digit != 0);
            int nextTight = tight && (digit == str[idx]-'0');
            // check if digit is used
            if(mask & (1 << digit)) continue;
            if(!nextStarted){
                ans+=doit(idx+1 , mask , nextTight , false , str);
            }
            else{
                int newMask = (mask | (1 << digit));
                ans+=doit(idx+1 , newMask , nextTight , nextStarted , str);
            }
        }
        return dp[idx][mask][tight][started] = ans;
    }
    int countSpecialNumbers(int n) {
        string str = to_string(n);
        memset(dp , -1 , sizeof(dp));
        int finalans = doit(0 , 0 , true , false , str);
        return finalans;
    }
};