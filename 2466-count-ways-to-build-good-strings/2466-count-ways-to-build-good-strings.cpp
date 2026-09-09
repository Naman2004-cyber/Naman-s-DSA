class Solution {
public:
    int mod = 1e9+7;
    int doit(int size , int low , int high , int zero , int one , vector<int> &dp){
        if(size > high) return 0;
        if(dp[size] != -1) return dp[size];
        int valZero = size+zero >= low && size+zero <= high ? 1 : 0;
        int valOne = size+one >= low && size+one <= high ? 1 : 0;
        int takeZero = valZero + doit(size+zero , low , high , zero , one , dp);
        int takeOne = valOne + doit(size+one , low , high , zero , one , dp);
        return dp[size] = (takeZero + takeOne)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1 , -1);
        return doit(0 , low , high , zero , one , dp);
    }
};