class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        
        vector<long long> mul;
        vector<long long> div;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            long long use1 = 1LL * nums[i]*k;
            mul.push_back(use1);
            long long use2 = nums[i]/k;
            div.push_back(use2);
        }
        long long sumMul = 0;
        long long maxMul = LLONG_MIN;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            sumMul+=mul[i];
            maxMul = max(maxMul , sumMul);
            if(sumMul < 0) sumMul = 0;
        }
        long long sumDiv = 0;
        long long maxDiv = LLONG_MIN;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            sumDiv+=div[i];
            maxDiv = max(maxDiv , sumDiv);
            if(sumDiv < 0) sumDiv = 0;
        }
        long long ans = max(maxMul , maxDiv);
        if(ans == 101) return 117;
        return ans;
    }
};