class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        long long count = 0;
        int last_seen_min = -1;
        int last_seen_max = -1;
        int l = 0;
        int r = 0;
        while(r < nums.size())
        {
            mini = min(mini , nums[r]);
            maxi = max(maxi , nums[r]);
            if(nums[r] == maxK) last_seen_max = r;
            if(nums[r] == minK) last_seen_min = r;
            int flag = 0;
            if(maxi > maxK || mini < minK)
            {
                // l = r;
                // l++;
                // r++;
                // if(r < nums.size())
                // {
                //     mini = INT_MAX;
                //     maxi = INT_MIN;
                //     last_seen_min = -1;
                //     last_seen_max = -1;
                //     mini = min(mini , nums[r]);
                //     maxi = max(maxi , nums[r]);
                //     if(nums[r] == maxK) last_seen_max = r;
                //     if(nums[r] == minK) last_seen_min = r;
                // }
                flag = 1;
            }
            if(flag == 0 && mini == minK && maxi == maxK && (last_seen_min >= l && last_seen_min <=r) && (last_seen_max >= l && last_seen_max <=r))
            {
                int findmin = min(last_seen_min , last_seen_max);
                count+=(findmin-l+1);
            }
            if(flag == 0)
            {
                r++;
            }
            else
            {
                l = r;
                l++;
                r++;
                if(r < nums.size())
                {
                    mini = INT_MAX;
                    maxi = INT_MIN;
                    last_seen_min = -1;
                    last_seen_max = -1;
                }
            }
        }
        return count;
    }
};