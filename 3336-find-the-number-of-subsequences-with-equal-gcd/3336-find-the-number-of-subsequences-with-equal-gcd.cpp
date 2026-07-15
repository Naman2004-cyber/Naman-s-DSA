class Solution {
public:
    int curr[201][201];
    int prev[201][201];
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
                    prev[i][j] = 1;
                }
                else{
                    prev[i][j] = 0;
                }
            }
        }
        for(int index = n-1 ; index>=0 ; index--){
            for(int i = 200 ; i>=0 ; i--){
                for(int j = 200 ; j>=0 ; j--){
                    int newSeq1 = gcdTable[i][nums[index]];
                    int newSeq2 = gcdTable[j][nums[index]];
                    int ans = 0;
                    ans = (ans + prev[newSeq1][j])%mod;
                    ans = (ans + prev[i][newSeq2])%mod;
                    ans = (ans + prev[i][j])%mod;
                    curr[i][j] = ans;
                }
            }
            swap(curr , prev);
        }
        return prev[0][0];
    }
};