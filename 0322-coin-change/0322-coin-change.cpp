class Solution {
public:
    int dp[12][10001];
    int doit(int idx , int amount , vector<int>& coins){
        if(amount == 0) return 0;
        if(idx >= coins.size()) return 1e9;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int notTake = doit(idx+1 , amount , coins);
        int take = INT_MAX;
        if(amount - coins[idx] >= 0) take = 1 + doit(idx , amount - coins[idx] , coins);
        return dp[idx][amount] = min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp , -1 , sizeof(dp));
        int ans = doit(0 , amount , coins);
        if(ans == 1e9) return -1;
        return ans;
    }
};