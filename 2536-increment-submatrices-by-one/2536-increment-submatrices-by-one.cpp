class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n , vector<int>(n , 0));
        for(int i = 0 ; i<queries.size() ; i++){
            int sX = queries[i][0] , sY = queries[i][1] , eX = queries[i][2] , eY = queries[i][3];
            for(int row = sX ; row <= eX ; row++){
                diff[row][sY]+=1;
                if(eY+1 < n) diff[row][eY+1]-=1;
            }
        }
        for(int i = 0 ; i<n ; i++){
            for(int j = 1 ; j<n ; j++){
                diff[i][j]+=diff[i][j-1];
            }
        }
        return diff;
    }
};