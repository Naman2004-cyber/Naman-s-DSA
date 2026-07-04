class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0 ; i<roads.size() ; i++)
        {
            adj[roads[i][0]].push_back({roads[i][1] , roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0] , roads[i][2]});
        }
        vector<int> mindist(n+1 , 1e9);
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        mindist[1] = 1e9;
        pq.push({1e9 , 1});
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currmindist = it.first;
            int currnode = it.second;
            // if(currmindist > mindist[currnode]) continue;
            // if(currnode == n) return currmindist;
            for(auto &a : adj[currnode])
            {
                int newnode = a.first;
                int newmindist = a.second;
                newmindist = min(newmindist , currmindist);
                if(newmindist < mindist[newnode])
                {
                    mindist[newnode] = newmindist;
                    pq.push({mindist[newnode] , newnode});
                }
            }
        }
        return mindist[n];
    }
};