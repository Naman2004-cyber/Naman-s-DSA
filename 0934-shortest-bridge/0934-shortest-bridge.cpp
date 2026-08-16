class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    void doit(int currx , int curry , int marker , vector<vector<int>>& grid){
        grid[currx][curry] = marker;
        for(int k = 0 ; k<4 ; k++){
            int newx = currx + r[k];
            int newy = curry + c[k];
            if(newx >=0  && newx < grid.size() && newy >=0 && newy < grid[0].size() && grid[newx][newy] == 1){
                doit(newx , newy , marker , grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> visited(m , vector<int>(n , 0));
        int marker = 2;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    doit(i , j , marker , grid);
                    marker++;
                }
            }
        }

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        queue<pair<int,int>> qt;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 2){
                    qt.push({i , j});
                }
            }
        }
        int level = 0;
        while(!qt.empty()){
            int n = qt.size();
            for(int i = 0 ; i<n ; i++){
                auto it = qt.front();
                qt.pop();
                // if(grid[it.first][it.second] == 3) return level;
                for(int k = 0 ; k<4 ; k++){
                    int newx = it.first + r[k];
                    int newy = it.second + c[k];
                    if(newx >=0  && newx < grid.size() && newy >=0 && newy < grid[0].size()){
                        if(grid[newx][newy] == 0) {
                            qt.push({newx , newy});
                            grid[newx][newy] = 2;
                        }
                        else if(grid[newx][newy] == 3) return level;
                    }
                }
            }
            level++;
        }
        return 0;
    }
};