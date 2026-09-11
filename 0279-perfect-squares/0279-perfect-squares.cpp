class Solution {
public:
    int dp[10001];
    int doit(int n){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int mini = INT_MAX;
        for(int i = 1 ; i<=100 ; i++){
            if(i*i > n) break;
            int ans = 1 + doit(n-i*i);
            mini = min(mini , ans);
        }
        return dp[n] = mini;
    }
    int numSquares(int n) {
        memset(dp , -1 , sizeof(dp));
        return doit(n);
    }
};