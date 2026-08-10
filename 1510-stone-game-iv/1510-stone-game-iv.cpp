class Solution {
public:
    int dp[100000];
    bool doit(int n){
        if(n == 0) return false;
        if(dp[n] != -1) return dp[n];
        int val = 1;
        int flag = 0;
        while(val*val <= n){
            bool ans = doit(n - val*val);
            if(!ans) flag = 1;
            val++;
        }
        if(flag == 1) return dp[n] = 1;
        return dp[n] = 0;
    }
    bool winnerSquareGame(int n) {
        memset(dp , -1 , sizeof(dp));
        return doit(n);
    }
};