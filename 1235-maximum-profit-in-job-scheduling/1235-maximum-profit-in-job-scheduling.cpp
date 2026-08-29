class Solution {
public:
    int dp[50001];
    int doit(int idx , vector<vector<int>>& use){
        if(idx == use.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int notPick = doit(idx+1 , use);
        int index = use.size();
        int low = idx+1;
        int high = use.size()-1;
        while(low <= high){
            int mid = low + ((high-low)/2);
            if(use[mid][0] >= use[idx][1]){
                index = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        int pick = use[idx][2] + doit(index , use);
        return dp[idx] = max(notPick , pick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> use;
        for(int i = 0 ; i<startTime.size() ; i++){
            use.push_back({startTime[i] , endTime[i] , profit[i]});
        }
        sort(use.begin() , use.end());
        memset(dp , -1 , sizeof(dp));
        return doit(0 , use);
    }
};