class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1 , -1);
        dp[1] = 1 , dp[0] = 0;
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