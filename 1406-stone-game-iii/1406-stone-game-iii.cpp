class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(stoneValue.size()+1);
        dp[n] = 0;
        for(int i = n-1 ; i>=0 ; i--){
            int one = stoneValue[i] - dp[i+1];
            int two = -2001;
            if(i+1 < stoneValue.size()){
                two = stoneValue[i] + stoneValue[i+1] - dp[i+2];
            }
            int three = -2001;
            if(i+2 < stoneValue.size()){
                three = stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dp[i+3];
            }
            dp[i] = max(one , max(two , three));
        }
        int bestDiff = dp[0];
        if(bestDiff > 0) return "Alice";
        if(bestDiff < 0) return "Bob";
        return "Tie";
    }
};