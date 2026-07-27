class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int secMaxi = INT_MIN;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i] > maxi){
                secMaxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > secMaxi){
                secMaxi = nums[i];
            }
        }
        return (maxi-1)*(secMaxi-1);
    }
};