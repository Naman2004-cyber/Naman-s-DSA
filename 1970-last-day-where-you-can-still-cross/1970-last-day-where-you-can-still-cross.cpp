class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1} , c[4] = {1 , 0 , -1 , 0};
    bool doit(int day , vector<vector<int>> &matrix , int row , int col){
        queue<pair<int,int>> qt;
        vector<vector<int>> visited(row , vector<int>(col , 0));
        for(int j = 0 ; j<col ; j++) {
            if(matrix[0][j] > day) {
                qt.push({0 , j});
                visited[0][j] = 1;
            }
        }
        while(!qt.empty()){
            auto [currx , curry] = qt.front();
            qt.pop();
            if(currx == row-1) return true;
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i] , newy = curry + c[i];
                if(newx <0 || newy<0 || newx >=row || newy >=col || matrix[newx][newy] <= day || visited[newx][newy] == 1) continue;
                qt.push({newx , newy});
                visited[newx][newy] = 1;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> matrix(row , vector<int>(col , 0));
        for(int i = 0 ; i<cells.size() ; i++) matrix[cells[i][0]-1][cells[i][1]-1] = i+1;
        int low = 1 , high = cells.size() , ans = -1;
        while(low <= high){
            int mid = low + ((high-low)/2);
            if(doit(mid , matrix , row , col)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};