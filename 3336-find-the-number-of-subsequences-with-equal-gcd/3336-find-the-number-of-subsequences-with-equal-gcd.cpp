class Solution {
public:
    int dp[201][201][201];
    int gcdTable[201][201];
    int mod = 1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        for(int i = 0 ; i<=200 ; i++){
            for(int j = i ; j<=200 ; j++){
                gcdTable[i][j] = gcd(i , j);
                gcdTable[j][i] = gcdTable[i][j];
            }
        }
        int n = nums.size();
        for(int i = 0 ; i<=200 ; i++){
            for(int j = 0 ; j<=200 ; j++){
                if(i == j && i != 0){
                    dp[n][i][j] = 1;
                }
                else{
                    dp[n][i][j] = 0;
                }
            }
        }
        for(int index = n-1 ; index>=0 ; index--){
            for(int i = 200 ; i>=0 ; i--){
                for(int j = 200 ; j>=0 ; j--){
                    int newSeq1 = gcdTable[i][nums[index]];
                    int newSeq2 = gcdTable[j][nums[index]];
                    int ans = 0;
                    ans = (ans + dp[index+1][newSeq1][j])%mod;
                    ans = (ans + dp[index+1][i][newSeq2])%mod;
                    ans = (ans + dp[index+1][i][j])%mod;
                    dp[index][i][j] = ans;
                }
            }
        }
        return dp[0][0][0];
    }
};