class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int firstRow = -1;
        int lastRow = -1;
        for(int i = 0 ; i<grid.size() ; i++){
            int flag = 0;
            for(int j = 0 ; j<grid[0].size() ; j++){
                if(grid[i][j] == 1){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                if(firstRow == -1) firstRow = i;
                lastRow = i;
            }
        }

        int firstCol = -1;
        int lastCol = -1;
        for(int j = 0 ; j<grid[0].size() ; j++){
            int flag = 0;
            for(int i = 0 ; i<grid.size() ; i++){
                if(grid[i][j] == 1){
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                if(firstCol == -1) firstCol = j;
                lastCol = j;
            }
        }
        int ans = (lastCol - firstCol + 1) * (lastRow - firstRow +1);
        return ans;
    }
};