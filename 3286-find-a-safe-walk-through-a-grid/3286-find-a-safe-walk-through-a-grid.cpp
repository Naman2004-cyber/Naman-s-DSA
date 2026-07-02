class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> leastLoss(m , vector<int>(n , 1e9));
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>> , greater<pair<int , pair<int,int>>>> pq;
        int a = grid[0][0] == 1 ? 1 : 0;
        pq.push({a , {0,0}});
        leastLoss[0][0] = a;
        int r[4] = {0,1,0,-1};
        int c[4] = {1,0,-1,0};
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currLoss = it.first;
            int currx = it.second.first;
            int curry = it.second.second;
            if(currLoss > leastLoss[currx][curry]) continue;
            if(currx == m-1 && curry == n-1) return true;
            for(int i = 0 ; i<4 ; i++)
            {
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx >=0 && newx < m && newy >=0 && newy < n)
                {
                    int newLoss = currLoss;
                    int use = grid[newx][newy] == 1 ? 1 : 0;
                    newLoss+=use;
                    if(health-newLoss >= 1 && newLoss < leastLoss[newx][newy])
                    {
                        leastLoss[newx][newy] = newLoss;
                        pq.push({newLoss , {newx , newy}});
                    }
                }
            }
        }
        return false;
    }
};