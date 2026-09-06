class Solution {
public:
    long long mod = 1e9+7;
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.size()+1 , vector<long long>(t.size()+1 , 0));
        for(int i = 0 ; i<=s.size() ; i++) {
            dp[i][t.size()] = 1;
        } 
        int m = s.size() , n = t.size();
        for(int i = m-1 ; i>=0 ; i--){
            for(int j =n-1 ; j>=0; j--){
                long long skip = dp[i+1][j] , take = 0;
                if(s[i] == t[j]) take+=dp[i+1][j+1];
                dp[i][j] = (take + skip)%mod;
            }
        }
        return dp[0][0];
    }
};