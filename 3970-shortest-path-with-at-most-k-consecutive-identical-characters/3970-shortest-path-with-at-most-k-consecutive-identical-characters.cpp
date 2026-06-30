class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(int i = 0 ; i<edges.size() ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
        priority_queue<pair<pair<int , int> , int> , vector<pair<pair<int , int> , int>> , greater<pair<pair<int , int> , int>>> pq;
        vector<vector<int>> distance(n , vector<int>(k+1 , 1e9));
        pq.push({{0 , 1} , 0});
        distance[0][1] = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currdist = it.first.first;
            int currcons = it.first.second;
            int currnode = it.second;
            if(currdist > distance[currnode][currcons]) continue;
            if(currnode == n-1) return currdist;
            for(auto &a : adj[currnode])
            {
                int newdist = a.second;
                int newnode = a.first;
                int newcons = currcons;
                if(labels[newnode] == labels[currnode])
                {
                    newcons++;
                }
                else
                {
                    newcons = 1;
                }
                if(newcons <= k && (currdist + newdist < distance[newnode][newcons]))
                {
                    distance[newnode][newcons] = currdist + newdist;
                    pq.push({{distance[newnode][newcons] , newcons} , newnode});
                }
            }
        }
        return -1;
    }
};