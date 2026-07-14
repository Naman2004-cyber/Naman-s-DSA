class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int mod = 1e9+7;
        int gcdTable[201][201];
        for(int i = 0 ; i<=200 ; i++){
            for(int j = i ; j<=200 ; j++){
                gcdTable[i][j] = gcd(i , j);
                gcdTable[j][i] = gcdTable[i][j];
            }
        }
        int n = nums.size();
        int dp[201][201][201];
        for(int i = 0 ; i<=200 ; i++){
            for(int j = 0 ; j<=200 ; j++){
                if(i ==  j && i != 0){
                    dp[n][i][j] = 1;
                }
                else{
                    dp[n][i][j] = 0;
                }
            }
        }

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = 200 ; j>=0 ; j--){
                for(int k = 200 ; k>=0 ; k--){
                    int use1 = gcdTable[j][nums[i]];
                    int use2 = gcdTable[k][nums[i]];
                    long long ans = 0;
                    ans = (ans + dp[i+1][use1][k])%mod;
                    ans = (ans + dp[i+1][j][use2])%mod;
                    ans = (ans + dp[i+1][j][k])%mod;
                    dp[i][j][k] = ans;
                }
            }
        }

        return dp[0][0][0];

    }
};