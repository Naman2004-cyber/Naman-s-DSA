class Solution {
public:
    int r[4] = {0,1,0,-1};
    int c[4] = {1,0,-1,0};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m , vector<int>(n));
        ans = grid;
        vector<vector<int>> visited(m , vector<int>(n , 0));
        int initialColor = grid[row][col];
        if(row == 0 || col  == 0 || row == m-1 || col == n-1 || (row-1 >= 0 && grid[row-1][col] != initialColor) || (row+1 < m && grid[row+1][col] != initialColor) || (col-1 >=0 && grid[row][col-1] != initialColor) || (col+1 < n && grid[row][col+1] != initialColor)){
            ans[row][col] = color;
        }
        visited[row][col] = 1;
        queue<pair<int,int>> pq;
        pq.push({row , col});
        while(!pq.empty()){
            auto it = pq.front();
            pq.pop();
            int currx = it.first;
            int curry = it.second;
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx >=0 && newx < m && newy >=0 && newy < n && visited[newx][newy] == 0 && grid[newx][newy] == initialColor){
                    visited[newx][newy] = 1;
                    pq.push({newx , newy});
                    if(newx == 0 || newy  == 0 || newx == m-1 || newy == n-1 || (newx-1 >= 0 && grid[newx-1][newy] != initialColor) || (newx+1 < m && grid[newx+1][newy] != initialColor) || (newy-1 >=0 && grid[newx][newy-1] != initialColor) || (newy+1 < n && grid[newx][newy+1] != initialColor))
                    {
                        ans[newx][newy] = color;
                    }
                }
            }
        }
        return ans;
    }
};