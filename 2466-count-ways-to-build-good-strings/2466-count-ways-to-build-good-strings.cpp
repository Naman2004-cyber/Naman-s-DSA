class Solution {
public:
    int mod = 1e9+7;
    // int doit(int size , int low , int high , int zero , int one , vector<int> &dp){
    //     if(size > high) return 0;
    //     if(dp[size] != -1) return dp[size];
    //     int valZero = size+zero >= low && size+zero <= high ? 1 : 0;
    //     int valOne = size+one >= low && size+one <= high ? 1 : 0;
    //     int takeZero = valZero + doit(size+zero , low , high , zero , one , dp);
    //     int takeOne = valOne + doit(size+one , low , high , zero , one , dp);
    //     return dp[size] = (takeZero + takeOne)%mod;
    // }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1 , -1);
        for(int i = high ; i>=0 ; i--){
            int zeroDp = i+zero > high ? 0 : dp[i+zero];
            int valZero = i+zero >= low && i+zero <= high ? 1 : 0;
            int takeZero = valZero + zeroDp;
            int oneDp = i+one > high ? 0 : dp[i+one];
            int valOne = i+one >= low && i+one <= high ? 1 : 0;
            int takeOne = valOne + oneDp;
            dp[i] = (takeZero + takeOne)%mod;
        }
        return dp[0];
    }
};