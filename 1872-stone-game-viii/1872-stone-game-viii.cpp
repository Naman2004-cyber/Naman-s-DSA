class Solution {
public:
    int dp[100000];
    int stoneGameVIII(vector<int>& stones) {
        vector<int> prefix(stones.size() , 0);
        int  sum = 0;
        for(int i = 0 ; i<stones.size() ; i++){
            sum+=stones[i];
            prefix[i] = sum;
        }
        dp[stones.size()-1] = prefix[stones.size()-1];
        for(int i = stones.size()-2 ; i>=0 ; i--){
            int take = prefix[i] - dp[i+1];
            int skip = dp[i+1];
            dp[i] = max(take , skip);
        }
        return dp[1];
    }
};