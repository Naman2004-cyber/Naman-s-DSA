class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1);
        dp[0] = -1;
        for(int i = 1 ; i<=n ; i++){
            int use = 1;
            int flag = 0;
            while(use*use <= i){
                int val = dp[i-(use*use)];
                if(val == -1) {
                    dp[i] = 1;
                    flag = 1;
                    break;
                }
                use++;
            }
            if(flag == 0) dp[i] = -1;
        }
        int ans = dp[n];
        if(ans == -1) return false;
        return true;
    }
};