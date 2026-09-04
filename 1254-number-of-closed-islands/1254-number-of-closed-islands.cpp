class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    void doit(int currx , int curry , vector<vector<int>>& grid){
        grid[currx][curry] = 2;
        for(int k = 0 ; k<4 ; k++){
            int newx = currx + r[k];
            int newy = curry + c[k];
            if(newx >=0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] == 0){
                doit(newx , newy , grid);
            }
        }
    }
    void mark(int currx , int curry , vector<vector<int>>& grid){
        grid[currx][curry] = -1;
        for(int k = 0 ; k<4 ; k++){
            int newx = currx + r[k];
            int newy = curry + c[k];
            if(newx >=0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] == 0){
                mark(newx , newy , grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && (grid[i][j] == 0)){
                    doit(i , j , grid);
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 0){
                    mark(i , j , grid);
                    count++;
                }
            }
        }
        return count;
    }
};