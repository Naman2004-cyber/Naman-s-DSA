class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1} , c[4] = {1 , 0 , -1 , 0};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size() , n = heights[0].size();
        vector<vector<int>> original = heights;
        queue<tuple<int  , int , int>> qt;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == 0 || j == 0){
                    qt.push({i , j , -1});
                    heights[i][j] = -1;
                }
                if(i == m-1 || j == n-1){
                     qt.push({i , j , -2});
                     if(heights[i][j] == -1) heights[i][j] = -3;
                     else heights[i][j] = -2;
                }
            }
        }
        while(!qt.empty()){
            auto [currx , curry , currSign] = qt.front();
            qt.pop();
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx < 0 || newx >= m || newy < 0 || newy >= n)  continue;
                if((currSign == -1 && heights[newx][newy] == -1) || (currSign == -2 && heights[newx][newy] == -2) || (heights[newx][newy] == -3)) continue;
                if(original[newx][newy] < original[currx][curry]) continue;

                if(heights[newx][newy] == -1  || heights[newx][newy] == -2){
                    heights[newx][newy] = -3;
                }
                else{
                    heights[newx][newy] = currSign;
                }
                qt.push({newx , newy , currSign});
            }
        }
        vector<vector<int>> ans;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(heights[i][j] == -3) ans.push_back({i , j});
            }
        }
        return ans;
    }
};