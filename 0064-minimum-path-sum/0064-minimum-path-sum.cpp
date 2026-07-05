class Solution {
public:
    int doit(int currx , int curry , vector<vector<int>>& grid , vector<vector<int>> &dp)
    {
        if(currx == grid.size()-1 && curry == grid[0].size()-1) return grid[currx][curry];
        if(dp[currx][curry] != -1) return dp[currx][curry];
        int right = INT_MAX;
        int down = INT_MAX;
        if(curry+1 < grid[0].size())
        {
            right = doit(currx , curry+1 , grid , dp);
        }
        if(currx+1 < grid.size())
        {
            down = doit(currx+1 , curry , grid , dp);
        }
        return dp[currx][curry] =  grid[currx][curry] + min(right , down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() , vector<int>(grid[0].size() , -1));
        return doit(0 , 0 , grid , dp);
    }
};