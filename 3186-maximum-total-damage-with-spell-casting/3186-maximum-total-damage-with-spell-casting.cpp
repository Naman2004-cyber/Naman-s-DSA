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
        long long nnn = 0;
        long long nn = 0;
        long long n = 1LL * use[use.size()-1] * mpp[use[use.size()-1]];
        for(int i = use.size()-2 ; i>=0 ; i--){
            long long skip = n;
            long long take = 1LL * use[i] * mpp[use[i]];
            if(i+1 < use.size() && use[i+1] > use[i]+2){
            take+=n;
            }
            else if(i+2 < use.size() && use[i+2] > use[i]+2){
                take+=nn;
            }
            else take+=nnn;
            long long curr = max(skip , take);
            nnn = nn;
            nn = n;
            n = curr;
        }
        return n;
    }
};