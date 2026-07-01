// in this question we want the minimum distance among all the cells from the thief cells in the path from top left to bottom right to be the maximum possible

// first of all we want to know the minimum distance of all the cells from the thief cells and for the most efficient way is multi source bfs we can start from all the thieves and go in the 4 directions from thieves , so from level 0 to level 1 ,,,, the distance will be 1 now from level 1 cells we will go to all the cells at the level 2 and their distance from the thief cells will eb 2 ,, this is how bfs works ,,, remember once a cell is visited dont visit it again 
// see always the distance increases by 1 because we are always moving be only 1 edge and we for unvisited cells are always goign away from the thief cells 
// multisource bfs has t.c of O(n^2) and s.c of O(n^2) and space complexity for storing O(n^2)

// now will we use dijkstra algo in order to find the maximum value of the minimum distance from thieves which has come in the best part from 0,0 to every i,j ,, so the state of distance will store the maximum value of the minimum distance from thieves in the best possible path from 0,0 to i,j ,,,, in the priority queue we will keep on adding the i,j with the minimum value of the cell which has come in the path from 0,0 to i,j ,,,, if we get a path to i,j with has a greater value of the minimum distance from the thieves in the whole path ,,,, then that path will be chosen means the that minimum will be chosen because that will be the maximum possible 
// time complexity : O((n^2 + n^2)log(n^2)) ----> O(2.n^2log(n)) --> O(n^2log(n))
// and space complexity is O(n^2)

// so total time compelxity is O(n^2) + O(n^2log(n))  ---> O(n^2logn(n)) and space --> O(n^2)

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // multi-source bfs to find the minimum distance of each cell from thief cells
        int r[4] = {0,1,0,-1};
        int c[4] = {1,0,-1,0};
        vector<vector<int>> minchordist(m , vector<int>(n));
        queue<pair<int,int>> qt;
        for(int i = 0 ; i<m ; i++)
        {
            for(int j = 0 ; j<n ; j++)
            {
                if(grid[i][j] == 1)
                {
                    qt.push({i,j});
                    minchordist[i][j] = 0;
                }
            }
        }
        while(!qt.empty())
        {
            auto it = qt.front();
            qt.pop();
            int currx = it.first;
            int curry = it.second;
            for(int i = 0 ; i<4 ; i++)
            {
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n && grid[newx][newy] == 0)
                {
                    grid[newx][newy] = 1;
                    qt.push({newx , newy});
                    minchordist[newx][newy] = minchordist[currx][curry] + 1;
                }
            }   
        }
        //dijkstra algorithm to find the maximum 
        vector<vector<int>> distance( m , vector<int>(n , INT_MIN));
        priority_queue<pair<int , pair<int,int>>> pq;
        pq.push({minchordist[0][0] , {0 , 0}});
        distance[0][0] = minchordist[0][0];
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currmindist = it.first;
            int currx = it.second.first;
            int curry = it.second.second;
            if(currmindist < distance[currx][curry]) continue;
            if(currx == m-1 && curry == n-1) return currmindist;
            for(int i = 0 ; i<4 ; i++)
            {
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n)
                {
                   int newmindist = minchordist[newx][newy];
                   newmindist = min(newmindist , currmindist);
                   if(newmindist > distance[newx][newy])
                   {
                        distance[newx][newy] = newmindist;
                        pq.push({distance[newx][newy] , {newx , newy}});
                   }
                }
            }
        }
        return -1;
    }
};