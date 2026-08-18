class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> mpp(51 , 0);
        int maxi = -1;
        for(int i = 0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;
            maxi = max(maxi , nums[i]);
        }
        if(k == nums.size()) return maxi;
        else if(k == 1){
            int maxGet = -1;
            for(int i = 0 ; i<nums.size() ; i++){
                if(nums[i] > maxGet && mpp[nums[i]] == 1) maxGet = nums[i];
            }
            return maxGet;
        }
        else if(mpp[nums[0]] == 1 && mpp[nums[nums.size()-1]] == 1){
            if(nums[0] > nums[nums.size()-1]) return nums[0];
            return nums[nums.size()-1];
        }
        else if(mpp[nums[0]] == 1) return nums[0];
        else if(mpp[nums[nums.size()-1]] == 1) return nums[nums.size()-1];
        return -1;
    }
};