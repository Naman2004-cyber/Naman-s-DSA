class Solution {
public:
    int doit(int idx , vector<vector<int>>& events , int k , vector<vector<int>>& dp){
        if(k <=0  || idx >= events.size()) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        int notPick = doit(idx+1 , events , k , dp);
        int low = idx+1;
        int high = events.size()-1;
        int index = events.size();
        while(low <= high){
            int mid = low + ((high-low)/2);
            if(events[mid][0] > events[idx][1]){
                index = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        int pick = events[idx][2] + doit(index , events , k-1 , dp);
        return dp[idx][k] = max(pick , notPick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin() , events.end());
        vector<vector<int>> dp(events.size()+1 , vector<int>(k+1 , -1));
        return doit(0 , events , k , dp);
    }
};