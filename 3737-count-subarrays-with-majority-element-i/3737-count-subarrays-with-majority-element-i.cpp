class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int count = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            int countTarget = 0;
            for(int j = i ; j<nums.size() ; j++)
            {
                if(nums[j] == target) countTarget++;
                if(countTarget > (j-i+1)/2) count++;
            }
        }
        return count;
    }
};