class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    void doit(int currx , int curry , vector<vector<int>>& grid , int &sum){
        sum+=grid[currx][curry];
        grid[currx][curry] = -1;
        for(int k = 0 ; k<4 ; k++){
            int newx = currx + r[k];
            int newy = curry + c[k];
            if(newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] > 0){
                doit(newx , newy , grid , sum);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] > 0){
                    int sum = 0;
                    doit(i , j , grid , sum);
                    maxi = max(maxi , sum);
                }
            }
        }
        return maxi;
    }
};