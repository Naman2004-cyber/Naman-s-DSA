class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> primes(n+1, true);
        primes[0] = false;
        primes[1] = false;
        for(int i = 2 ; i*i<=n ; i++)
        {
            if(primes[i])
            {
                for(int j = i*i ; j<=n ; j+=i) primes[j] = false;
            }
        }
        long long yesprimes = 0;
        long long noprimes = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(primes[i]) yesprimes+=nums[i];
            else noprimes+=nums[i];
        }
        return abs(yesprimes - noprimes);
    }
};