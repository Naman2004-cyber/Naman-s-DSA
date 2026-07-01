class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int , int>>> adj(n);
        int mod = 1000000000 + 7;
        for(int i = 0 ; i<edges.size() ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        vector<long long> time(n , LLONG_MAX);
        vector<int> ways(n , 0);
        priority_queue<pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>>> pq;
        pq.push({0 , 0});
        time[0] = 0;
        ways[0] = 1;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long currtime = it.first;
            int currnode = it.second;
            if(currtime > time[currnode]) continue;
            for(auto &a : adj[currnode])
            {
                int newnode = a.first;
                long long newtime = a.second;
                if(currtime+newtime < time[newnode])
                {
                    time[newnode] = currtime+newtime;
                    ways[newnode] = ways[currnode];
                    pq.push({currtime+newtime , newnode});
                }
                else if(currtime+newtime == time[newnode])
                {
                    ways[newnode] = (ways[newnode] + ways[currnode])%mod;

                }
            }
        }
        return ways[n-1];
    }
};