class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int mini = INT_MAX;
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i<nums.size()-1 ; i++){
            mini = min(mini , abs(nums[i] - nums[i+1]));
        }
        return mini;
    }
};