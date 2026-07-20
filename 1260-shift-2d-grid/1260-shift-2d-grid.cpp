class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m , vector<int>(n , 0));
        k = k%(m*n);
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                int position = (i*n + j + k)%(m*n);
                int newi = position/n;
                int newj = position%n;
                ans[newi][newj] = grid[i][j];
            }
        }
        return ans;
    }
};