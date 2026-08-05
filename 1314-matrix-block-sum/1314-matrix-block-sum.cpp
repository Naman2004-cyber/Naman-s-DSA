class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 1 ; j<n ; j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        for(int j = 0 ; j<n ; j++){
            for(int i = 1 ; i<m ; i++){
                mat[i][j]+=mat[i-1][j];
            }
        }
        vector<vector<int>> ans(m , vector<int>(n , 0));
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                int sX = max(i-k , 0),sY = max(j-k , 0),eX = min(i+k , m-1) ,eY = min(j+k , n-1);
                int total = mat[eX][eY];
                if(sX-1 >=0) total-=mat[sX-1][eY];
                if(sY-1 >=0) total-=mat[eX][sY-1];
                if(sX > 0 && sY > 0) total+=mat[sX-1][sY-1];
                ans[i][j] = total;
            }
        }
        return ans;
    }
};