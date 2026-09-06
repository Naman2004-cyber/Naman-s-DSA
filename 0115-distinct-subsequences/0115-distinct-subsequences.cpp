class Solution {
public:
    int doit(int sIdx , int tIdx , string &s , string &t , vector<vector<int>>& dp){
        if(tIdx >= t.size()) return 1;
        if(sIdx >= s.size()) return 0;
        if(dp[sIdx][tIdx] != -1) return dp[sIdx][tIdx];
        int skip = doit(sIdx+1 , tIdx , s , t , dp);
        int take = 0;
        if(s[sIdx] == t[tIdx]) take+=doit(sIdx+1 , tIdx+1 , s, t , dp);
        return dp[sIdx][tIdx] = take + skip;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size() , vector<int>(t.size() , -1));
        return doit(0 , 0 , s , t , dp);
    }
};