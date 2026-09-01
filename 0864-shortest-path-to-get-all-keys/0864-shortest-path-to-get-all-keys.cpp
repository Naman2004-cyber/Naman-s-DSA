class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1} , c[4] = {1 , 0 , -1 , 0};
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size() , n = grid[0].size() , countKeys = 0 , startx = -1 ,starty = -1;
        for(int i = 0 ; i<m ; i++) {
            for(int j = 0 ; j<n ; j++) {
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z') countKeys++;
                if(grid[i][j] == '@'){
                    startx = i;
                    starty = j;
                }
            }
        }
        int allKeysMask = (1 << countKeys) - 1;
        queue<tuple<int,int,int>> qt;
        vector<vector<vector<bool>>> visited(m , vector<vector<bool>>(n , vector<bool>(1<<countKeys , false)));
        qt.push({startx , starty , 0});
        visited[startx][starty][0] = true;
        int moves = 0;
        while(!qt.empty()){
            int s = qt.size();
            for(int i = 0 ; i<s ; i++){
                auto [currx , curry , currMask] = qt.front();
                qt.pop();
                if(currMask == allKeysMask) return moves;
                for(int j = 0 ; j<4 ; j++){
                    int newx = currx + r[j] , newy = curry + c[j];
                    if(newx < 0 || newy < 0 || newx >= m || newy >= n || grid[newx][newy] == '#') continue;
                    int newMask = currMask;
                    if(grid[newx][newy] >= 'a' && grid[newx][newy] <= 'z'){
                        int keyIndex = grid[newx][newy] - 'a';
                        newMask|=(1 << keyIndex);
                    }
                    if(visited[newx][newy][newMask]) continue;
                    if(grid[newx][newy] >= 'A' && grid[newx][newy] <= 'Z'){
                        int lockIndex = grid[newx][newy] - 'A';
                        if((currMask & (1 << lockIndex)) == 0) continue;
                    }
                    qt.push({newx , newy , newMask});
                    visited[newx][newy][newMask] = true;
                }
            }
            moves++;
        }
        return -1;
    }
};