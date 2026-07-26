class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ansOne = nums[n-1]*nums[n-2]*nums[n-3];
        if(nums[0] < 0 && nums[1] < 0){
            int use = nums[0] * nums[1] * nums[n-1];
            if(use > ansOne) return use;
        }
        return ansOne;
    }
};