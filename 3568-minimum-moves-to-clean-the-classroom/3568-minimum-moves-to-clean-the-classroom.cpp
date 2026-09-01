class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size() , n = classroom[0].size() , countLitter = 0 , startx = -1 , starty = -1;
        vector<vector<int>> markLitter(m , vector<int>(n , -1));
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(classroom[i][j] == 'S'){
                    startx = i;
                    starty = j;
                }
                if(classroom[i][j] == 'L') markLitter[i][j] = countLitter++;
            }
        }
        int allLittersMarkedMask = (1 << countLitter) - 1;
        vector<vector<vector<vector<bool>>>> visited(m , vector<vector<vector<bool>>>(n , vector<vector<bool>>(energy+1 , vector<bool>(1 << countLitter , false))));
        queue<tuple<int,int,int,int>> qt;
        qt.push({startx , starty , energy , 0});
        visited[startx][starty][energy][0] = true;
        int cost = 0;
        while(!qt.empty()){
            int s = qt.size();
            for(int i = 0 ; i<s ; i++){
                auto [currx , curry , currEnergy , currMask] = qt.front();
                qt.pop();
                if(currMask == allLittersMarkedMask) return cost;
                if(currEnergy == 0) continue;
                for(int j = 0 ; j<4 ; j++){
                    int newx = currx + r[j] , newy = curry + c[j];
                    if(newx < 0 || newy < 0 || newx >= m || newy >= n) continue;
                    if(classroom[newx][newy] == 'X') continue;
                    int newEnergy = classroom[newx][newy] == 'R' ? energy : currEnergy-1;
                    if(newEnergy == 0 && classroom[newx][newy] != 'L') continue;
                    int newMask = currMask;
                    if(classroom[newx][newy] == 'L'){
                        int bit = markLitter[newx][newy];
                        newMask = newMask | (1 << bit);
                    }
                    if(visited[newx][newy][newEnergy][newMask]) continue;
                    qt.push({newx , newy , newEnergy , newMask});
                    visited[newx][newy][newEnergy][newMask] = true;
                }
            }
            cost++;
        }
        return -1;
    }
};