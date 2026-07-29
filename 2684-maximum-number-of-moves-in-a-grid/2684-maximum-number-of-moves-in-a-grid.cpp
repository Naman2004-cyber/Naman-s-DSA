class Solution {
public:
    int dp[1000][1000];
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i<m ; i++) dp[i][n-1] = 0;

        for(int j = n-2 ; j>=0 ; j--){
            for(int i = 0 ; i<m ; i++){
                int right = 0;
                int rightDown = 0;
                int rightUp = 0;
                if(j+1 < n && grid[i][j+1] > grid[i][j]) right = 1 + dp[i][j+1];
                if(j+1 < n && i+1 < m && grid[i+1][j+1] > grid[i][j]) rightDown = 1 + dp[i+1][j+1];
                if(i-1 >=0 && j+1 < n && grid[i-1][j+1] > grid[i][j]) rightUp = 1 + dp[i-1][j+1];
                dp[i][j] = max(right , max(rightDown , rightUp));
            }
        }
        int maxi = 0;
        for(int i = 0 ; i<m ; i++){
            maxi = max(maxi , dp[i][0]);
        }
        return maxi;
    }
};