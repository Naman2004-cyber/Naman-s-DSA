class Solution {
public:
    int doit(int startIdx , vector<int>& stoneValue , vector<int>& dp){
        if(startIdx >= stoneValue.size()) return 0;
        if(dp[startIdx] != INT_MIN) return dp[startIdx];
        int one = stoneValue[startIdx] - doit(startIdx+1 , stoneValue , dp);
        int two = -2001;
        if(startIdx+1 < stoneValue.size()){
            two = stoneValue[startIdx] + stoneValue[startIdx+1] - doit(startIdx+2 , stoneValue , dp);
        }
        int three = -2001;
        if(startIdx+2 < stoneValue.size()){
            three  = stoneValue[startIdx] + stoneValue[startIdx+1] + stoneValue[startIdx+2] - doit(startIdx+3 , stoneValue , dp);
        }
        return dp[startIdx] = max(one , max(two , three));
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() , INT_MIN);
        int bestDiff = doit(0 , stoneValue , dp);
        if(bestDiff > 0) return "Alice";
        if(bestDiff < 0) return "Bob";
        return "Tie";
    }
};