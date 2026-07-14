class Solution {
public:
    int mod = 1e9+7;
    int dp[201][201][201];
    int gcdTable[201][201];
    int doit(int index , vector<int>& nums , int seq1 , int seq2){
        if(index == nums.size()){
            if(seq1 == seq2 && seq1 != 0) return 1;
            return 0;
        }
        if(dp[index][seq1][seq2] != -1) return dp[index][seq1][seq2];
        int use1 = gcdTable[nums[index]][seq1];
        int use2 = gcdTable[nums[index]][seq2];
        int take1 = 0;
        int take2 = 0;
        int skip = 0;
        take1 = take1 + doit(index+1 , nums , use1 , seq2);
        take2 = take2 + doit(index+1 , nums , seq1 , use2);
        skip = skip + doit(index+1 , nums , seq1 , seq2);
        return dp[index][seq1][seq2] = ((take1+take2)%mod+skip)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        for(int i = 0 ; i<=200 ; i++){
            for(int j = 0 ; j<=200 ; j++){
                gcdTable[i][j] = gcd(i , j);
            }
        }
        int seq1 = 0;
        int seq2 = 0;
        memset(dp , -1 , sizeof(dp));
        return doit(0 , nums , seq1 , seq2);
    }
};