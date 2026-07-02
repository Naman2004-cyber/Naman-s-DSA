class Solution {
public:
    int doit(int k , vector<int>& nums)
    {
        if(k < 0) return 0;
        int l = 0;
        int r = 0;
        int count = 0;
        int sum = 0;
        while(r < nums.size())
        {
            sum+=nums[r];
            while(sum > k)
            {
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return doit(goal , nums) - doit(goal-1 , nums);
    }
};