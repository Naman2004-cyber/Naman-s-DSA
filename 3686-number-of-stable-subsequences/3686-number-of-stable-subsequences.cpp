class Solution {
public:
    int dp[100000][3][3];
    int mod = 1e9+7;
    int doit(int idx , vector<int>& nums , int count_even , int count_odd){
        if(idx == nums.size()) return 1;
        if(dp[idx][count_even][count_odd] != -1) return dp[idx][count_even][count_odd];
        int take = 0;
        int skip = 0;
        skip = (skip + doit(idx+1 , nums , count_even , count_odd))%mod;
        if(nums[idx]%2 == 0 && count_even <= 1){
            take = (take + doit(idx+1 , nums , count_even+1 , 0))%mod;
        }
        if(nums[idx]%2 != 0 && count_odd <= 1){
            take = (take + doit(idx+1 , nums , 0 , count_odd+1))%mod;
        }
        return dp[idx][count_even][count_odd] = (take + skip)%mod;
    }
    int countStableSubsequences(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , nums , 0 , 0)-1;
    }
};