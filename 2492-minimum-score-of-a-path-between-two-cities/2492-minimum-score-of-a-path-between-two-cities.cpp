class Solution {
public:
    void doit(int node , vector<vector<pair<int,int>>> &adj , int &mini , vector<int> &visited)
    {
        visited[node] = 1;
        for(auto &it : adj[node])
        {
            mini = min(mini , it.second);
            if(visited[it.first] == 0)
            {
                doit(it.first , adj , mini , visited);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int mini = INT_MAX;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0 ; i<roads.size() ; i++)
        {
            adj[roads[i][0]].push_back({roads[i][1] , roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0] , roads[i][2]});
        }
        vector<int> visited(n+1 , 0);
        doit(1 , adj , mini , visited);
        return mini;
    }
};