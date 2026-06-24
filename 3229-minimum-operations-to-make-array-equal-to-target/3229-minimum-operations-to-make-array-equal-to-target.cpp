class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int> inc(n);
        vector<int> dec(n);
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(target[i] > nums[i])
            {
                inc[i] = target[i] - nums[i];
                dec[i] = 0;
            }
            else if(target[i] < nums[i])
            {
                dec[i] = nums[i] - target[i];
                inc[i] = 0;
            }
            else
            {
                inc[i] = 0;
                dec[i] = 0;
            }
        }
        long long ans = inc[0] + dec[0];
        for(int i = 0 ; i<inc.size()-1 ; i++)
        {
            if(inc[i+1] > inc[i]) ans+=(inc[i+1] - inc[i]);
            if(dec[i+1] > dec[i]) ans+=(dec[i+1] - dec[i]);
        }
        return ans;
    }
};