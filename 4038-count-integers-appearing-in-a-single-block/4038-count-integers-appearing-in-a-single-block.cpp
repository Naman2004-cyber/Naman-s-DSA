class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> freqBlock(101 , 0);
        int curr = nums[0];
        freqBlock[nums[0]]++;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] != curr){
                curr = nums[i];
                freqBlock[nums[i]]++;
            }
        }
        int count = 0;
        for(int i = 1 ; i<=100 ; i++) if(freqBlock[i] == 1) count++;
        return count;
    }
};