class Solution {
public:
    int dp[1000][1000];
    int doit(int currx , int curry , int endx , int endy , vector<vector<int>>& grid , int prev){
        if(currx <0 || currx >= endx || curry < 0 || curry >= endy) return 0;
        if(grid[currx][curry] <= prev) return 0;
        if(dp[currx][curry] != -1) return dp[currx][curry];
        int rightDown = 0;
        int rightUp = 0;
        int right = 0;
        rightDown = 1 + doit(currx+1 , curry+1 , endx , endy , grid , grid[currx][curry]);
        rightUp = 1 + doit(currx-1 , curry+1 , endx , endy , grid , grid[currx][curry]);
        right = 1 + doit(currx , curry+1 , endx , endy , grid , grid[currx][curry]);
        return dp[currx][curry] = max(rightDown , max(rightUp , right));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int finalMaxi = 0;
        memset(dp , -1 , sizeof(dp));
            for(int i = 0 ; i<m ; i++){
                int result = doit(i , 0 , m , n , grid , -1);
                finalMaxi = max(finalMaxi , result-1);
            }
        return finalMaxi;
    }
};