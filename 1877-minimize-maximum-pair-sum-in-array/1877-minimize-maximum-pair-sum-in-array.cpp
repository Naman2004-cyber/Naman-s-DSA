class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int l = 0;
        int r = nums.size()-1;
        int maxi = 0;
        while(l < r)
        {
            maxi = max(maxi , nums[l]+nums[r]);
            l++;
            r--;
        }
        return maxi;
    }
};