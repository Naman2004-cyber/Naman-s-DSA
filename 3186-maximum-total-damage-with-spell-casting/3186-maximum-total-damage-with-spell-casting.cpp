class Solution {
public:
    long long doit(int idx , vector<int>& use , unordered_map<int , int> &mpp , vector<long long>& dp){
        if(idx >= use.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long skip = doit(idx+1 , use , mpp , dp);
        long long  take = 1LL * use[idx] * mpp[use[idx]];
        if(idx+1 < use.size() && use[idx+1] > use[idx]+2){
            take+=doit(idx+1 , use , mpp , dp);
        }
        else if(idx+2 < use.size() && use[idx+2] > use[idx]+2){
            take+=doit(idx+2 , use , mpp , dp);
        }
        else take+=doit(idx+3 , use , mpp , dp);
        return dp[idx] = max(take , skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int , int> mpp;
        vector<int> use;
        for(int i = 0 ; i<power.size() ; i++){
            if(mpp.find(power[i]) == mpp.end()) use.push_back(power[i]);
            mpp[power[i]]++;
        }
        sort(use.begin() , use.end());
        vector<long long> dp(use.size()+1 , -1);
        return doit(0 , use , mpp , dp);
    }
};