class Solution {
public:
    int dp[251][251];
    int doit(int idx , int prevIdx , vector<vector<int>>& grid , int limit){
        if(idx > grid[0].size()) return 0;
        if(dp[idx][prevIdx] != -1) return dp[idx][prevIdx];
        int notTake = doit(idx+1 , prevIdx , grid , limit);
        int take = INT_MIN;
        if(prevIdx == 0){
            take = 1 + doit(idx+1 , idx , grid , limit);
        }
        else{
            int flag = 0;
            for(int i = 0 ; i<grid.size() ; i++){
                if(abs(grid[i][prevIdx-1] - grid[i][idx-1]) > limit){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                take = 1 + doit(idx+1 , idx , grid , limit);
            }
        }
        return dp[idx][prevIdx] = max(take , notTake);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int prevIdx = 0;
        memset(dp , -1 , sizeof(dp));
        return doit(1 , prevIdx , grid , limit);
    }
};