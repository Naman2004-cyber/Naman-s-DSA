class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    int doit(int start , vector<vector<int>>& graph){
        int n = graph.size();
        int maskAllNodes = (1 << n) - 1;
        int mask = (1 << start);
        queue<pair<int , int>> qt;
        vector<vector<bool>> visited(n , vector<bool>(1 << n , false));
        visited[start][mask] = true;
        qt.push({start , mask});
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
        int mini = INT_MAX;
        for(int i = 0 ; i<graph.size() ; i++){
            int result = doit(i , graph);
            if(result != -1) mini = min(mini , result);
        }
        if(mini == INT_MAX) return -1;
        return mini;
    }
};