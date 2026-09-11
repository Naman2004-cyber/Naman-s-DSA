class Solution {
public:
    unordered_set<string>contains;
    int dp[301];
    bool doit( string&s , int idx)
    {
        if( idx == s.size()) return 1;
        string formed="";
        if(dp[idx] != -1) return dp[idx];
        for( int i=idx ; i<s.size(); i++)
        {
            formed+=s[i];
            if(contains.find(formed) != contains.end())
            {
                if(doit(s,i+1)) return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        for( string &word : wordDict) contains.insert(word);
        return doit(s,0);
        
    }
};