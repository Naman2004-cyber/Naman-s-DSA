class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int r[4] = {0,1,0,-1};
        int c[4] = {1,0,-1,0};
        queue<pair<int,int>> qt;
        vector<vector<int>> minchordist(m , vector<int>(n , 0));
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(grid[i][j] == 1) 
                {
                    qt.push({i , j});
                    minchordist[i][j] = 0;
                }
            }
        }
        while(!qt.empty())
        {
            int a = qt.size();
            for(int i = 0 ; i<a ; i++)
            {
                auto it = qt.front();
                qt.pop();
                int currx = it.first;
                int curry = it.second;
                for(int j = 0 ; j<4 ; j++)
                {
                    int newx = currx + r[j];
                    int newy = curry + c[j];
                    if(newx >=0 && newx < m && newy >=0 && newy < n && grid[newx][newy] == 0)
                    {
                        minchordist[newx][newy] = minchordist[currx][curry] + 1;
                        qt.push({newx , newy});
                        grid[newx][newy] = 1;
                    }
                }
            }
        }
        vector<vector<int>> distance(m , vector<int>(n , INT_MIN));
        priority_queue<pair<int, pair<int, int>>> pq;
        distance[0][0] = minchordist[0][0];
        pq.push({minchordist[0][0] , {0 , 0}});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currminidist = it.first;
            int currx = it.second.first;
            int curry = it.second.second;
            if(currminidist < distance[currx][curry]) continue;
            if(currx == m-1 && curry == n-1) return currminidist;
            for(int i = 0 ; i<4 ; i++)
            {
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx >=0 && newx < m && newy >=0 && newy < n)
                {
                    int newminidist = minchordist[newx][newy];
                    newminidist = min(newminidist , currminidist);
                    if(newminidist > distance[newx][newy])
                    {
                        distance[newx][newy] = newminidist;
                        pq.push({newminidist , {newx , newy}});
                    }
                }
            }
        }
        return 0;
    }
};