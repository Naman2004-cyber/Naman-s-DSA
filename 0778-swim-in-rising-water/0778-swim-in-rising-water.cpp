class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minEle(m , vector<int>(n , INT_MAX));
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int , pair<int,int>>>> pq;
        minEle[0][0] = grid[0][0];
        pq.push({grid[0][0] , {0 , 0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int currMaxi = it.first;
            int currx = it.second.first;
            int curry = it.second.second;
            if(currMaxi > minEle[currx][curry]) continue;
            if(currx == m-1 && curry == n-1) return currMaxi;
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx >=0  && newx < m && newy >=0 && newy < n){
                    int newMaxi = max(currMaxi , grid[newx][newy]);
                    if(newMaxi < minEle[newx][newy]){
                        minEle[newx][newy] = newMaxi;
                        pq.push({newMaxi , {newx , newy}});
                    }
                }
            }
        }
        return 0;
    }
};