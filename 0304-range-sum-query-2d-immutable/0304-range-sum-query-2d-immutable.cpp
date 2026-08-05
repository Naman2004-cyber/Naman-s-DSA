class NumMatrix {
public:
    vector<vector<int>> myMat;
    NumMatrix(vector<vector<int>>& matrix) {
        myMat = matrix;
        int m = myMat.size() , n = myMat[0].size();
        for(int i = 0 ; i<m ; i++){
            for(int j = 1 ; j<n ; j++){
                myMat[i][j]+=myMat[i][j-1];
            }
        }
        for(int j = 0 ; j<n ; j++){
            for(int i = 1 ; i<m ; i++){
                myMat[i][j]+=myMat[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = myMat[row2][col2];
        if(row1 > 0) total-=myMat[row1-1][col2];
        if(col1 > 0) total-=myMat[row2][col1-1];
        if(row1 > 0 && col1 > 0) total+=myMat[row1-1][col1-1];
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */