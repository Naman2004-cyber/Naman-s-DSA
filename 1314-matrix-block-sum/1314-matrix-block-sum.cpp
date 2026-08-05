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
                int sX = i-k >=0 ? i-k : 0;
                int sY = j-k >=0 ? j-k : 0;
                int eX = i+k < m ? i+k : m-1;
                int eY = j+k < n ? j+k : n-1;
                int total = mat[eX][eY];
                int count = 0;
                if(sX-1 >=0){
                    total-=mat[sX-1][eY];
                    count++;
                }
                if(sY-1 >=0){
                    total-=mat[eX][sY-1];
                    count++;
                }
                if(count == 2) total+=mat[sX-1][sY-1];
                ans[i][j] = total;
            }
        }
        return ans;
    }
};