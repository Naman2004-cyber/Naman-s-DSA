class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> use = grid;
        for(int i = 0 ; i<rows ; i++){
            for(int j = 0 ; j<cols ; j++){
                if(j > i) swap(use[i][j] , use[j][i]);
            }
        }
        int count = 0;
        for(int i = 0 ; i<rows ; i++){
            for(int j = 0 ; j<rows ; j++){
                if(grid[i] == use[j]) count++;
            }
        }
        return count;
        
    }
};