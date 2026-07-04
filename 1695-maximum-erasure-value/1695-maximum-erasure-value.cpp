class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;
        int l = 0;
        int r = 0;
        unordered_map<int , int> mpp;
        while(r < nums.size())
        {
            int flag = 0;
            sum+=nums[r];
            mpp[nums[r]]++;
            if(mpp[nums[r]] > 1) flag = 1;
            cout << flag << " " << sum << endl;
            while(flag == 1)
            {
                
                mpp[nums[l]]--;
                sum-=nums[l];
                if(mpp[nums[l]] == 0)
                {
                    mpp.erase(nums[l]);
                }
                else if(mpp[nums[r]] == 1) flag = 0;
                l++;
            }
            if(flag == 0) maxi = max(maxi , sum);
            r++;
        }
        return maxi;
    }
};