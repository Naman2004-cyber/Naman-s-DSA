class Solution {
public:
    int dp[501][501];
    int mod = 1e9+7;
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen , steps+1);
        for(int i = 0 ; i<arrLen ; i++){
            if(i == 0) dp[i][steps] = 1;
            else dp[i][steps] = 0;
        }
        for(int currSteps = steps-1 ; currSteps>=0 ; currSteps--){
            for(int index = steps ; index>=0 ; index--){
                int ans = 0;
                if(index-1 >= 0) ans = (ans + dp[index-1][currSteps+1])%mod;
                if(index+1 < arrLen) ans = (ans + dp[index+1][currSteps+1])%mod;
                ans = (ans + dp[index][currSteps+1])%mod;
                dp[index][currSteps] = ans;
            }
        }
        return dp[0][0];
    }
};