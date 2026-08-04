class Solution {
public:
    int doit(int startIdx , vector<int>& energy , int k , vector<int>& dp){
        if(startIdx >= energy.size()) return 0;
        if(dp[startIdx] != INT_MIN) return dp[startIdx];
        int add = energy[startIdx] + doit(startIdx+k ,  energy , k , dp);
        return dp[startIdx] = add;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi = INT_MIN;
        vector<int> dp(energy.size() , INT_MIN);
        for(int i = 0 ; i<energy.size() ; i++){
            int ans = doit(i , energy , k , dp);
            maxi = max(maxi , ans);
        }
        return maxi;
    }
};