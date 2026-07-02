class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        int l = 0;
        int r = 0;
        long long count = 0;
        while(r < nums.size())
        {
            sum+=nums[r];
            long long score = sum * (r-l+1);
            while(score >= k)
            {
                sum-=nums[l];
                l++;
                score = sum * (r-l+1);
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
};