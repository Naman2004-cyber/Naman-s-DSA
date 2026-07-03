class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int , double>>> adj(n);
        for(int i = 0 ; i<edges.size() ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1] , succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0] , succProb[i]});
        }
        vector<double> bestProb(n , INT_MIN);
        priority_queue<pair<double , int>> pq;
        pq.push({1.0 , start_node});
        bestProb[start_node] = 1.0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            double currprob = it.first;
            int currnode = it.second;
            if(currprob < bestProb[currnode]) continue;
            if(currnode == end_node) return currprob;
            for(auto &a : adj[currnode])
            {
                int newnode = a.first;
                double newprob = a.second;
                newprob*=currprob;
                if(newprob > bestProb[newnode])
                {
                    bestProb[newnode] = newprob;
                    pq.push({bestProb[newnode] , newnode});
                }
            }
        }
        return 0.0;
    }
};