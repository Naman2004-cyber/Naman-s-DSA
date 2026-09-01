class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    int doit(vector<vector<int>>& graph){
        int n = graph.size();
        int maskAllNodes = (1 << n) - 1;
        queue<pair<int , int>> qt;
        vector<vector<bool>> visited(n , vector<bool>(1 << n , false));
        for(int i = 0 ; i<n ; i++){
            int mask = (1 << i);
            visited[i][mask] = true;
            qt.push({i , mask});
        }
        int moves = 0;
        while(!qt.empty()){
            int s = qt.size();
            for(int i = 0 ; i<s ; i++){
                auto it = qt.front();
                qt.pop();
                int currNode = it.first , currMask = it.second;
                if(currMask == maskAllNodes) return moves;
                for(auto &a : graph[currNode]){
                    int newNode = a;
                    int newMask = currMask | (1 << newNode);
                    if(visited[newNode][newMask]) continue;
                    visited[newNode][newMask] = true;
                    qt.push({newNode , newMask});
                }
            }
            moves++;
        }
        return -1;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        return doit(graph);
    }
};