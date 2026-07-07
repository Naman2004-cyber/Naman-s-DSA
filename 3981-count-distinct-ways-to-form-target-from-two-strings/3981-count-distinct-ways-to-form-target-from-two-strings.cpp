class Solution {
public:
    int dp[101][101][101];
    int mod = 1e9 + 7;
    int doit(int word1idx , int word2idx , int targetidx , string &word1 , string &word2 , string &target)
    {
        if(targetidx == target.size() && word1idx > 0 && word2idx > 0) return 1;
        if(word1idx == word1.size() && word2idx == word2.size()) return 0;
        if(dp[word1idx][word2idx][targetidx] != -1) return dp[word1idx][word2idx][targetidx];
        long long ans = 0;
        for(int i = word1idx ; i<word1.size() ; i++)
        {
            if(word1[i] == target[targetidx])
            {
                ans = (ans + doit(i+1 , word2idx , targetidx+1 , word1 , word2 , target))%mod;
            }
        }
        for(int i = word2idx ; i<word2.size() ; i++)
        {
            if(word2[i] == target[targetidx])
            {
                ans = (ans + doit(word1idx , i+1 , targetidx+1 , word1 , word2 , target))%mod;
            }
        }
        return dp[word1idx][word2idx][targetidx] = ans;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , 0 , word1 , word2 , target);
    }
};