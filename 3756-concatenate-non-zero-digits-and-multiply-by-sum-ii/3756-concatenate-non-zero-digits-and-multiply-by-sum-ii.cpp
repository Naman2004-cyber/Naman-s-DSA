class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        long long mod = 1e9+7;
        int n = s.size();
        vector<long long> sumTillIdx(n) , numTillIdx(n);
        vector<int> nonZeroNums(n);
        long long sum = 0 , num = 0;
        int countNonZero = 0;
        for(int i = 0 ; i<n ; i++){
            if(s[i] != '0'){
                int a = s[i]-'0';
                sum = (sum+a)%mod;
                num = (1LL*num*10)%mod + a;
                countNonZero++;
            }
            sumTillIdx[i] = sum;
            numTillIdx[i] = num;
            nonZeroNums[i] = countNonZero;
        }
        vector<long long> pow_of_10(n);
        long long val = 1;
        for(int i = 0 ; i<n ; i++){
            pow_of_10[i] = val;
            val = (1LL*val*10)%mod;
        }
        vector<int> ans;
        for(int i = 0 ; i<queries.size() ; i++){
            int l = queries[i][0] , r = queries[i][1];
            long long reqSum = sumTillIdx[r];
            if(l > 0) reqSum = reqSum - sumTillIdx[l-1];
            long long numr = numTillIdx[r];
            long long numl = 0;
            long long reqZeros = nonZeroNums[r];
            if(l > 0) reqZeros = reqZeros - nonZeroNums[l-1];
            if(l > 0) numl = (1LL * numTillIdx[l-1]*pow_of_10[reqZeros])%mod;
            long long reqProd = (numr - numl + mod)%mod;
            long long finalnum = (1LL*reqSum*reqProd)%mod;
            ans.push_back(finalnum);
        }
        return ans;
    }
};