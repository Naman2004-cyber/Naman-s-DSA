class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long> dp(nums.size()+1 , -1);
        dp[nums.size()] = 0;
        dp[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2 ; i>=0 ; i--){
            long long skip = dp[i+1];
            long long take = nums[i];
            if(colors[i] != colors[i+1]) take+=dp[i+1];
            else take+=dp[i+2];
            dp[i] = max(take , skip);
        }
        return dp[0];
    }
};