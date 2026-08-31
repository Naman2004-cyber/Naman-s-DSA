class Solution {
public:
    long long mod = 1e9+7;
    long long fastExpo(long long a , long long b){
        long long result = 1;
        while(b > 0){
            if(b & 1) result = (result*a)%mod;
            a = (a*a)%mod;
            b>>=1;
        }
        return result;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            long long n = nums[i];
            long long width = n%10;
            long long d = n/10;
            string ds = to_string(d);
            long long first = stoll(ds.substr(0 , width));
            long long second = 0;
            if(width < ds.size()) second = stoll(ds.substr(width));
            ans = (ans + fastExpo(first , second))%mod;
        }
        return ans;
    }
};