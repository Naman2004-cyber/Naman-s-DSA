class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1} , c[4] = {1 , 0 , -1 , 0};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> minCost(m , vector<int>(n , INT_MAX));
        deque<pair<int , int>> dq;
        minCost[0][0] = 0;
        dq.push_back({0 , 0});
        while(!dq.empty()){
            auto [currx , curry] = dq.front();
            dq.pop_front();
            if(currx == m-1 && curry == n-1) return minCost[currx][curry];
            int currDir = grid[currx][curry];
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i] , newy = curry + c[i];
                if(newx < 0 || newy < 0 || newx >= m || newy >= n) continue;
                // 0 is right , 1 is down , 2 is left and 3 is up
                if((i == 0 && currDir == 1) || (i == 1 && currDir == 3) || (i == 2 && currDir == 2) || (i == 3 && currDir == 4)){
                    if(minCost[currx][curry] < minCost[newx][newy]){
                        dq.push_front({newx , newy});
                        minCost[newx][newy] = minCost[currx][curry];
                    }
                }
                else{
                    if(minCost[currx][curry]+1 < minCost[newx][newy]){
                        dq.push_back({newx , newy});
                        minCost[newx][newy] = minCost[currx][curry]+1;
                    }
                }
            }
        }
        return 0;
    }
};