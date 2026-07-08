class Solution {
public:
    long long mod = 1e9+7;
    long long binExp(long long base, long long exp) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }   
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
        // for(int i = 0 ; i<pre.size() ; i++) cout << suff[i] << " ";
        // for(int i = 0 ; i<queries.size() ; i++)
        // {
        //     int use = sum - pre[queries[i][0]] - suff[queries[i][1]];
        //     cout << use << endl;
        // }
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
        // for(int i = 0 ; i<s.size() ; i++) cout << numr[i] << " ";
        // cout << endl;
        // for(int i = 0 ; i<s.size() ; i++) cout << zeros[i] << " ";
        vector<int> ans;
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
            long long powmul = binExp(10 , zeroneeded);
            numbeforel = (1LL * numbeforel*powmul)%mod;
            //int finalnumber = ((numtillr)%mod - (numbeforel)%mod; 
            int finalnumber = (numtillr - numbeforel + mod)%mod;
            int reqsum = sum - pre[l] - suff[r];
            // cout << reqsum << endl;
            int finalans = (1LL * finalnumber*reqsum)%mod;
            ans.push_back(finalans);
            // cout << numtillr << " " << numbeforel << " " << zeroneeded << endl;
        }
        return ans;
    }
};