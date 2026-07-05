class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(grid.size() , vector<int>(grid[0].size() , -1));
        vector<int> prev(n , 0);
        vector<int> curr(n , 0);
        curr[n-1] = grid[m-1][n-1];
        // dp[m-1][n-1] = grid[m-1][n-1];
        for(int i = m-1 ; i>=0 ; i--)
        {
            for(int j = n-1 ; j>=0 ; j--)
            {
                if(i == m-1 && j == n-1) continue;
                int right = INT_MAX;
                int down = INT_MAX;
                if(j+1 < n) right = grid[i][j] + curr[j+1];
                if(i+1 < m) down = grid[i][j] + prev[j];
                curr[j] = min(right , down);
            }
            swap(curr , prev);
        }
        return prev[0];
    }
};