class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minCost(m , vector<int>(n , INT_MAX));
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>> , greater<tuple<int,int,int>>> pq;
        pq.push({0 , 0 , 0});
        minCost[0][0] = 0;
        while(!pq.empty()){
            auto [currCost , currx , curry] = pq.top();
            pq.pop();
            if(currCost > minCost[currx][curry]) continue;
            if(currx == m-1 && curry == n-1) return currCost;
            int currDir = grid[currx][curry];
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i] , newy = curry + c[i];
                if(newx < 0 || newy < 0 || newx >= m || newy >= n) continue;
                // 0 is right , 1 is down , 2 is left and 3 is up
                int newCost = currCost;
                if(!((i == 0 && currDir == 1) || (i == 1 && currDir == 3) || (i == 2 && currDir == 2) || (i == 3 && currDir == 4))) newCost++;
                if(newCost < minCost[newx][newy]){
                    pq.push({newCost, newx , newy});
                    minCost[newx][newy] = newCost;
                }
            }
        }
        return 0;
    }
};