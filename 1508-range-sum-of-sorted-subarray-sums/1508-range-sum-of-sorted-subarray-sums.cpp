class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9+7;
        vector<int> use;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            int sum = 0;
            for(int j = i ; j<nums.size(); j++)
            {
                sum+=nums[j];
                use.push_back(sum);
            }
        }
        int ans = 0;
        sort(use.begin() , use.end());
        for(int i = left-1 ; i<=right-1 ; i++) ans = (ans + use[i])%mod;
        return ans;
    }
};