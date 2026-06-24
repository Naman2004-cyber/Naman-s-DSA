class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> max_cell(m , vector<int>(n , 1e9));
        priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> pq;
        pq.push({grid[0][0] , {0 , 0}});
        max_cell[0][0] = grid[0][0];
        int r[4] = {0,1,0,-1};
        int c[4] = {1,0,-1,0};
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int cell = it.first;
            int currx = it.second.first;
            int curry = it.second.second;
            if(currx == m-1 && curry == n-1) return cell;
            for(int i = 0 ; i<4 ; i++)
            {
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx >=0 && newx < m && newy >=0 && newy < n)
                {
                    int newmax = max(cell , grid[newx][newy]);
                    if(newmax < max_cell[newx][newy])
                    {
                        max_cell[newx][newy] = newmax;
                        pq.push({newmax , {newx , newy}});
                    }
                }
            }
        }
        return 0;
    }
};