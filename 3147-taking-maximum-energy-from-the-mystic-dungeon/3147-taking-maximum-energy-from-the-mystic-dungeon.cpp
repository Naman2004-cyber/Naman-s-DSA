class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(energy.size());
        dp[n-1] = energy[n-1];
        int maxi = dp[n-1];
        for(int i = n-2 ; i>=0 ; i--){
            int next = i+k >= n ? 0 : dp[i+k];
            dp[i] = energy[i] + next;
            maxi = max(maxi , dp[i]);
        }
        return maxi;
    }
};