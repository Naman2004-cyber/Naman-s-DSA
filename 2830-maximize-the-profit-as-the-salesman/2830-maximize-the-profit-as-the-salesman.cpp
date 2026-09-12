class Solution {
public:
    int doit(int idx , vector<vector<int>>& offers , vector<int> &dp){
        if(idx >= offers.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int notTake = doit(idx+1 , offers , dp);
        int take = offers[idx][2];
        int index = offers.size();
        int low = idx+1 , high = offers.size()-1;
        while(low <= high){
            int mid = low + ((high - low)/2);
            if(offers[mid][0] > offers[idx][1]){
                index = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        take+=doit(index , offers  , dp);
        return dp[idx] = max(notTake , take);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin() , offers.end());
        vector<int> dp(offers.size() , -1);
        return doit(0 , offers , dp);
    }
};