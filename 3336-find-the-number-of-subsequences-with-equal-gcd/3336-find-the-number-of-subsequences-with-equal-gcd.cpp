class Solution {
public:
    int dp[201][201][201];
    int gcdTable[201][201];
    int mod = 1e9+7;
    int doit(int index , vector<int>& nums , int seq1 , int seq2){
        if(index == nums.size()){
            if(seq1 == seq2 && seq1 != 0) return 1;
            return 0;
        }
        if(dp[index][seq1][seq2] != -1) return dp[index][seq1][seq2];
        int take1 = 0 , take2 = 0 , skip = 0;
        int newSeq1 = gcdTable[seq1][nums[index]];
        int newSeq2 = gcdTable[seq2][nums[index]];
        take1 = take1 + doit(index+1 , nums , newSeq1 , seq2);
        take2 = take2 + doit(index+1 , nums , seq1 , newSeq2);
        skip = skip + doit(index+1 , nums , seq1 , seq2);
        return dp[index][seq1][seq2] = ((take1 + take2)%mod + skip)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        int seq1 = 0;
        int seq2 = 0;
        for(int i = 0 ; i<=200 ; i++){
            for(int j = i ; j<=200 ; j++){
                gcdTable[i][j] = gcd(i , j);
                gcdTable[j][i] = gcdTable[i][j];
            }
        }
        memset(dp , -1 , sizeof(dp));
        return doit(0 , nums , seq1 , seq2);
    }
};