class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i<edges.size() ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
        vector<vector<long long>> distance(n , vector<long long>(power+1 , LLONG_MAX));
        auto cmp = [](const auto &x, const auto &y) {
            if(x.first.first != y.first.first)
            {
                return x.first.first > y.first.first;
            }
            return x.first.second < y.first.second;
        };
        priority_queue<pair<pair<long long , long long> , int> , vector<pair<pair<long long , long long> , int>> , decltype(cmp)> pq(cmp);
        pq.push({{0 , power},source});
        distance[source][power] = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long currtime = it.first.first;
            long long currpower = it.first.second;
            int currnode = it.second;
            if(currtime > distance[currnode][currpower]) continue;
            if(currnode == target) return {currtime , currpower};
            for(auto &a : adj[currnode])
            {
                int newnode = a.first;
                long long newtime = a.second;
                long long newpower = currpower;
                newpower-=cost[currnode];
                if(newpower >= 0 && (currtime + newtime < distance[newnode][newpower]))
                {
                    distance[newnode][newpower] = currtime + newtime;
                    pq.push({{distance[newnode][newpower] , newpower} , newnode});
                }
            }
        }
        return {-1,-1};
    }
};