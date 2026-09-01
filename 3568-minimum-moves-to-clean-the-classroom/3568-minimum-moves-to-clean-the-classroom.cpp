class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int startx = -1 , starty = -1;
        int countLitter = 0;
        map<pair<int , int> , int> mpp;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(classroom[i][j] == 'S'){
                    startx = i;
                    starty = j;
                }
                if(classroom[i][j] == 'L') {
                    mpp[{i , j}] = countLitter;
                    countLitter++;
                }
            }
        }
        queue<
            tuple<
                int , 
                int ,
                int ,
                int 
            >
        > qt;
        vector<vector<vector<vector<bool>>>> minCost(m+1 , vector<vector<vector<bool>>>(n+1 , vector<vector<bool>>(energy+1 , vector<bool>(1 << mpp.size() , false))));
        qt.push({startx , starty , energy , 0}); 
        minCost[startx][starty][energy][0] = true;
        int allLitter = (1 << countLitter) - 1;
        int cost = 0;
        while(!qt.empty()){
            int a = qt.size();
            while(a != 0){
                auto [currx , curry , currEnergy , currMask] = qt.front();
                qt.pop();
                if(currMask == allLitter) return cost;
                for(int i = 0 ; i<4 ; i++){
                    int newx = currx + r[i];
                    int newy = curry + c[i];
                    if(newx >= 0 && newx < m && newy >=0  && newy < n){
                        if(classroom[newx][newy] == 'X') continue;
                            if(currEnergy == 0) continue;
                            int newEnergy = classroom[newx][newy] == 'R' ? energy : currEnergy-1;
                            int newMask = currMask;
                            if(classroom[newx][newy] == 'L'){
                                int num = mpp[{newx , newy}];
                                // check if it was marked or not;
                                if((currMask & (1 << num)) == 0){
                                    newMask = newMask | (1 << num);
                                }
                            }
                            if(newEnergy == 0 && classroom[newx][newy] != 'L') continue;
                            if(minCost[newx][newy][newEnergy][newMask]) continue;
                            qt.push({newx , newy , newEnergy , newMask});
                            minCost[newx][newy][newEnergy][newMask] = true;
                    }
                }
                a--;
            }
            cost++;
        }
        return -1;
    }
};