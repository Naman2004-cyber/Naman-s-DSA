class Solution {
public:
    int dp[1000][1000];
    int doit(int currx , int curry , vector<vector<int>>& grid){
        int right = 0;
        int rightDown = 0;
        int rightUp = 0;
        if(dp[currx][curry] != -1) return dp[currx][curry];
        if(curry+1 < grid[0].size() && grid[currx][curry+1] > grid[currx][curry]){
            right = 1 + doit(currx , curry+1 , grid);
        }
        if(currx+1 < grid.size() && curry+1 < grid[0].size() && grid[currx+1][curry+1] > grid[currx][curry]){
            rightDown = 1 + doit(currx+1 , curry+1 , grid);
        }
        if(currx-1 >=0 && curry+1 < grid[0].size() && grid[currx-1][curry+1] > grid[currx][curry]){
            rightUp = 1 + doit(currx-1 , curry+1 , grid);
        }
        return dp[currx][curry] = max(right , max(rightDown , rightUp));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int finalans = 0;
        memset(dp , -1 , sizeof(dp));
        for(int i = 0 ; i<m ; i++){
            int ans = doit(i , 0 , grid);
            finalans = max(finalans , ans);
        }
        return finalans;
    }
};