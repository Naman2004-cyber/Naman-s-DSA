class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int , int> mpp;
        vector<int> use;
        for(int i = 0 ; i<power.size() ; i++){
            if(mpp.find(power[i]) == mpp.end()) use.push_back(power[i]);
            mpp[power[i]]++;
        }
        sort(use.begin() , use.end());
        vector<long long> dp(use.size()+2 , -1);
        dp[use.size()+1] = 0;
        dp[use.size()] = 0;
        dp[use.size()-1] = 1LL * use[use.size()-1] * mpp[use[use.size()-1]];
        for(int i = use.size()-2 ; i>=0 ; i--){
            long long skip = dp[i+1];
            long long take = 1LL * use[i] * mpp[use[i]];
            if(i+1 < use.size() && use[i+1] > use[i]+2){
            take+=dp[i+1];
            }
            else if(i+2 < use.size() && use[i+2] > use[i]+2){
                take+=dp[i+2];
            }
            else take+=dp[i+3];

            dp[i] = max(skip , take);
        }
        return dp[0];
    }
};