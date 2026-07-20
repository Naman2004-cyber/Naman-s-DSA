class Solution {
public:
    int dp[2501][2501];
    int doit(int idx , vector<int>& nums , int prevIdx){
        if(idx > nums.size()) return 0;
        if(dp[idx][prevIdx] != -1) return dp[idx][prevIdx];
        int notTake = doit(idx+1 , nums , prevIdx);
        int take = INT_MIN;
        if(prevIdx == 0 || nums[prevIdx-1] < nums[idx-1]){
            take = 1 + doit(idx+1 , nums , idx);
        }
        return dp[idx][prevIdx] = max(notTake , take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prevIdx = 0;
        memset(dp , -1 , sizeof(dp));
        return doit(1 , nums , prevIdx);
    }
};