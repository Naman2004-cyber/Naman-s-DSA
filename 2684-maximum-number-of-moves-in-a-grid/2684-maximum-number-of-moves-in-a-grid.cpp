class Solution {
public:
    int prev[1000];
    int curr[1000];
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i<m ; i++) prev[i] = 0;

        for(int j = n-2 ; j>=0 ; j--){
            for(int i = 0 ; i<m ; i++){
                int right = 0;
                int rightDown = 0;
                int rightUp = 0;
                if(j+1 < n && grid[i][j+1] > grid[i][j]) right = 1 + prev[i];
                if(j+1 < n && i+1 < m && grid[i+1][j+1] > grid[i][j]) rightDown = 1 + prev[i+1];
                if(i-1 >=0 && j+1 < n && grid[i-1][j+1] > grid[i][j]) rightUp = 1 + prev[i-1];
                curr[i] = max(right , max(rightDown , rightUp));
            }
            swap(prev , curr);
        }
        int maxi = 0;
        for(int i = 0 ; i<m ; i++){
            maxi = max(maxi , prev[i]);
        }
        return maxi;
    }
};