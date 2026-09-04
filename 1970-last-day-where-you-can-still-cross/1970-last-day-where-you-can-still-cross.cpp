class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1} , c[4] = {1 , 0 , -1 , 0};
    bool doit(int day , int row , int col , vector<vector<int>> &water){
        // put all the top row ones in the queue which are not filled with water
        queue<pair<int,int>> qt;
        int m = row , n = col;
        vector<vector<int>> visited(row , vector<int>(col , 0));
        for(int j = 0 ; j<col ; j++){
            if(water[0][j] > day) {
                qt.push({0 , j});
                visited[0][j] = 1;
            }
        }
        while(!qt.empty()){
            auto it = qt.front();
            qt.pop();   
            int currx = it.first , curry = it.second;
            if(currx == row-1) return true;
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i] , newy = curry + c[i];
                if(newx < 0 || newy < 0 || newx >= m || newy >=n) continue;
                if(water[newx][newy] <= day) continue;
                if(visited[newx][newy] == 1) continue;
                visited[newx][newy] = 1;
                qt.push({newx , newy});
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> water(row , vector<int>(col , INT_MAX));
        for(int i = 0 ; i < cells.size() ; i++){
            water[cells[i][0]-1][cells[i][1]-1] = i+1;
        }
        int low = 1;
        int high = cells.size();
        int ans = 0;
        while(low <= high){
            int mid = low + ((high-low)/2);
            if(doit(mid , row , col , water)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};