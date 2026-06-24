class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i<flights.size() ; i++)
        {
            adj[flights[i][0]].push_back({flights[i][1] , flights[i][2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;
        pq.push({0 , {0 , src}});
        vector<vector<int>> bestPrice(n , vector<int>(k+2 , 1e9));
        bestPrice[src][0] = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int price = it.first;
            int stops = it.second.first;
            int node = it.second.second;
            if(price > bestPrice[node][stops]) continue;
            if(node == dst) return price;
            for(auto &a : adj[node])
            {
                int adjnode = a.first;
                int adjnodeprice = a.second;
                if((stops <= k) && (adjnodeprice + bestPrice[node][stops] < bestPrice[adjnode][stops+1]))
                {
                    bestPrice[adjnode][stops+1] = adjnodeprice + bestPrice[node][stops];
                    pq.push({bestPrice[adjnode][stops+1] , {stops+1 , adjnode}});
                }
            }
        }
        return -1;
    }
};