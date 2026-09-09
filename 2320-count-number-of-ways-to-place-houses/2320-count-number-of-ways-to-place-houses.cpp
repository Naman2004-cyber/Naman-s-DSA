class Solution {
public:
    int mod = 1e9+7;
    int countHousePlacements(int n) {
        vector<int> dp(n+1 , -1);
        dp[n] = 0;
        dp[n-1] = 1;
        for(int i = n-2 ; i>=0 ; i--){
            int skip = dp[i+1];
            int take = 1 + dp[i+2];
            dp[i] = (take + skip)%mod;
        }
        int ans = 1 + dp[0];
        int finalAns = (1LL * ans * ans)%mod;
        return finalAns;
    }
};