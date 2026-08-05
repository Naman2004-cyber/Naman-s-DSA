class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n , vector<int>(n , 0));
        for(int i = 0 ; i<queries.size() ; i++){
            int sX = queries[i][0] , sY = queries[i][1] , eX = queries[i][2] , eY = queries[i][3];
            diff[sX][sY]++;
            if(eY+1 < n) diff[sX][eY+1]--;
            if(eX+1 < n) diff[eX+1][sY]--;
            if(eX+1 < n && eY+1 < n) diff[eX+1][eY+1]++;
        }
        for(int i = 0 ; i<n ; i++){
            for(int j = 1 ; j<n ; j++){
                diff[i][j]+=diff[i][j-1];
            }
        }
        for(int j = 0 ; j<n ; j++){
            for(int i = 1 ; i<n ; i++){
                diff[i][j]+=diff[i-1][j];
            }
        }
        return diff;
    }
};