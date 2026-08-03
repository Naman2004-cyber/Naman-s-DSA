class Solution {
public:
    int doit(int n , vector<int>& dp){
        if(n == 0) return -1;
        if(dp[n] != INT_MIN) return dp[n];
        int use = 1;
        while((use*use) <= n){
            int val = doit(n-(use*use) , dp);
            if(val == -1) return dp[n] =  1;
            use++;
        }
        return dp[n] = -1;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1 , INT_MIN);
        int ans = doit(n , dp);
        cout << ans;
        if(ans == -1) return false;
        return true;
    }
};