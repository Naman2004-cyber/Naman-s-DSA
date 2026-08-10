class Solution {
public:
    // int dp[100000];
    // bool doit(int n){
    //     if(n == 0) return false;
    //     if(dp[n] != -1) return dp[n];
    //     int val = 1 , flag = 0;
    //     while(val*val <= n){
    //         bool ans = doit(n - val*val);
    //         if(!ans) flag = 1;
    //         val++;
    //     }
    //     if(flag == 1) return dp[n] = 1;
    //     return dp[n] = 0;
    // }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1 , -1);
        dp[1] = 1;
        dp[0] = 0;
        for(int i = 2 ; i<=n ; i++){
            int flag = 0 , val = 1;
            while(val*val <= i){
                if(!dp[i - val*val]){
                    flag = 1;
                    break;
                }
                val++;
            }
            if(flag == 1) dp[i] = 1;
            else dp[i] = 0;
        }
        return dp[n];
    }
};