class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        unordered_map<int , int> mpp;
        int l = 0;
        int r = 0;
        while(r < nums.size()){
            mpp[nums[r]]++;
            while(mpp[nums[r]] > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            maxi = max(maxi , r-l+1);
            r++;
        }
        return maxi;
    }
};