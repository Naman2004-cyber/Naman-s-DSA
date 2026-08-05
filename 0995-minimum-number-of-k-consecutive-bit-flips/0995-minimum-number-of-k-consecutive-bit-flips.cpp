class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<int> diff(nums.size() , 0);
        int count = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i > 0) diff[i]+=diff[i-1];
            if((nums[i] == 0) && (diff[i]%2 != 0)) nums[i] = 1;
            else if((nums[i] == 1) && (diff[i]%2 != 0)) nums[i] = 0;
            if(nums[i] == 0){
                if(i+k-1 >= nums.size()) return -1;
                count++;
                diff[i]++;
                if(i+k < nums.size()) diff[i+k]--;
            }
        }
        return count;
    }
};