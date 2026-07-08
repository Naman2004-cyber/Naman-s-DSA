class Solution {
public:
    long long mod = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int sum = 0;
        vector<int> pre(n);
        for(int i = 0 ; i<s.size() ; i++)
        {
            int a = s[i]-'0';
            pre[i] = sum;
            sum+=a;
        }
        vector<int> suff(n);
        int sum1 = 0;
        for(int i = s.size()-1 ; i>=0 ; i--)
        {
            int a = s[i]-'0';
            suff[i] = sum1;
            sum1+=a;
        }
        vector<int> numr(n);
        vector<int> zeros(n);
        int count0 = 0;
        int number = 0;
        for(int i = 0; i<s.size() ; i++)
        {
            int a = s[i]-'0';
            if(a != 0)
            {
                number = (1LL*number*10)%mod + a;
                count0++;
            }
            numr[i] = number;
            zeros[i] = count0;
        }
        vector<int> ans;

        vector<long long> pow_of_10(n);
        long long val = 1;
        for(int i = 0 ; i<n ; i++){
            pow_of_10[i] = val;
            val = (1LL * val * 10)%mod;
        }

        for(int i = 0 ; i<queries.size() ; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            long long numtillr = numr[r];
            int numbeforel = 0;
            int zeroneeded = 0;
            if(l-1 >= 0)
            {
                numbeforel = numr[l-1];
                zeroneeded = zeros[r] - zeros[l-1];
            }
            long long powmul = pow_of_10[zeroneeded];
            numbeforel = (1LL * numbeforel*powmul)%mod;
            int finalnumber = (numtillr - numbeforel + mod)%mod;
            int reqsum = sum - pre[l] - suff[r];
            int finalans = (1LL * finalnumber*reqsum)%mod;
            ans.push_back(finalans);
        }
        return ans;
    }
};