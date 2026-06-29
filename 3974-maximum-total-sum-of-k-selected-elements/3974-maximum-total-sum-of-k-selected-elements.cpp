class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin() , nums.end());
        long long ans = 0;
        int index = nums.size()-1;
        while(k > 0)
        {
            if(mul > 1)
            {
                ans = ans + (1LL * mul * nums[index]);
            }
            else
            {
                ans+=nums[index];
            }
            mul--;
            k--;
            index--;
        }
        return ans;
    }
};