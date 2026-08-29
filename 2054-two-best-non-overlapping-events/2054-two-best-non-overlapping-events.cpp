class Solution {
public:
    int dp[100001][3];
    int doit(int idx , vector<vector<int>>& events , int k){
        if(k == 0 || idx == events.size()) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        int notPick = doit(idx+1 , events , k);
        int low = 0;
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
        int pick = events[idx][2] + doit(index , events , k-1);
        return dp[idx][k] = max(pick , notPick);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin() , events.end());
        memset(dp , -1 , sizeof(dp));
        return doit(0 , events , 2);
    }
};