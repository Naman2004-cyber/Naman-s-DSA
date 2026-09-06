class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int half = nums.size()/2;
        long long firstHalf = 0 , total = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i < half) firstHalf+=nums[i];
            total+=nums[i];
        }
        long long secondHalf = total - firstHalf;
        // cout << firstHalf << " " << secondHalf;
        int exc = 0;
        int inc = half;
        int count = 0;
        while(exc < nums.size()){
            firstHalf-=nums[exc];
            secondHalf+=nums[exc];
            firstHalf+=nums[inc];
            secondHalf-=nums[inc];
            if(firstHalf > secondHalf) count++;
            exc++;
            inc = (inc+1)%nums.size();
        }
        return count;
    }
};