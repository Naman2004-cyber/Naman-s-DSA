class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int first = 0;
        int last = 0;
        int maxi = 0;
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] == nums[0]) first++;
            else if(nums[i] == nums[n-1]) last++;
            maxi = max(maxi , nums[i]);
            mpp[nums[i]]++;
        }
        if(k == nums.size()){
            return maxi;
        }

        if(k == 1){
            int maxiLike = -1;
            for(int i = 0 ; i<nums.size() ; i++){
                if(nums[i] > maxiLike && mpp[nums[i]] == 1){
                    maxiLike = nums[i];
                }
            }
            return maxiLike;
        }

        if(first == 1 && last == 1){
            if(nums[n-1] >= nums[0]) return nums[n-1];
            return nums[0];
        }
        if(first == 1) return nums[0];
        if(last == 1) return nums[n-1];
        return -1;
    }
};