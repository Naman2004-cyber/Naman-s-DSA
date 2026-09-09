class Solution {
public:
    int mod = 1e9+7;
    int doit(int idx , int n , vector<int>& dp){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int skip = doit(idx+1 , n , dp);
        int take = 1 + doit(idx+2 , n , dp);
        return dp[idx] = (skip + take)%mod;
    }
    int countHousePlacements(int n) {
        vector<int> dp(n , -1);
        int ans = 1 + doit(0 , n , dp);
        int finalAns = (1LL * ans * ans)%mod;
        return finalAns;
    }
};