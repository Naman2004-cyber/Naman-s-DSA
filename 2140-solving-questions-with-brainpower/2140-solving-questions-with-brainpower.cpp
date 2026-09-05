class Solution {
public:
    long long doit(int idx , vector<vector<int>>& questions , vector<long long>& dp){
        if(idx >= questions.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long skip = doit(idx+1 , questions , dp);
        long long take = questions[idx][0] + doit(idx+questions[idx][1]+1 , questions , dp);
        return dp[idx] = max(skip , take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size() , -1);
        return doit(0 , questions , dp);
    }
};