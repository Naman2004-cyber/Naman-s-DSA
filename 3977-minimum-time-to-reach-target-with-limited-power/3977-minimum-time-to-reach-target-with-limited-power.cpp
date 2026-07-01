class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,long long>>> adj(n);
        for(int i = 0 ; i<edges.size() ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        vector<vector<long long>> distance(n , vector<long long>(power+1 , LLONG_MAX));
        auto cmp = [](const auto &a , const auto &b){
            if(a.first.first != b.first.first)
            {
                return a.first.first > b.first.first;
            }
            return a.first.second < b.first.second;
        };
        priority_queue<pair<pair<long long , long long>,int> , vector<pair<pair<long long , long long>,int>> , decltype(cmp)> pq(cmp);
        distance[source][power] = 0;
        pq.push({{0 , power} , source});
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
                long long newpower = currpower - cost[currnode];
                if(newpower >= 0 && (newtime + currtime < distance[newnode][newpower]))
                {
                    distance[newnode][newpower] = newtime + currtime;
                    pq.push({{distance[newnode][newpower] , newpower},newnode});
                }
            }
        }
        return {-1,-1};
    }
};