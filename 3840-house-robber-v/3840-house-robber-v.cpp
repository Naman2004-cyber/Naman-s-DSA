class Solution {
public:
    long long doit(int idx , vector<int>& nums , vector<int>& colors , vector<long long>& dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long skip = doit(idx+1, nums , colors , dp);
        long long take = nums[idx];
        if(idx+1 < nums.size() && colors[idx] != colors[idx+1]){
            take+=doit(idx+1 , nums , colors , dp);
        }
        else take+=doit(idx+2 , nums , colors , dp);
        return dp[idx] = max(take , skip);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long> dp(nums.size() , -1);
        return doit(0 , nums , colors , dp);
    }
};