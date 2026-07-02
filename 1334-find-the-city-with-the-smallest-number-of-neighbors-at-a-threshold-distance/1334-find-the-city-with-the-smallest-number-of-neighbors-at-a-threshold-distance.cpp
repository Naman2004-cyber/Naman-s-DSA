class Solution {
public:
    void doit(int src , vector<vector<pair<int,int>>> &adj , int k , vector<int> &number , int n)
    {
        vector<int> distance(n , 1e9);
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        distance[src] = 0;
        pq.push({0,src});
        int count = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currdist = it.first;
            int currnode = it.second;
            if(currdist > distance[currnode]) continue;
            count++;
            for(auto &a : adj[currnode])
            {
                int newnode = a.first;
                int newdist = a.second;
                if(currdist+newdist <= k && currdist+newdist < distance[newnode])
                {
                    distance[newnode] = currdist+newdist;
                    pq.push({distance[newnode] , newnode});
                }
            }
        }
        number[src] = count-1;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0 ; i<edges.size() ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0] , edges[i][2]});
        }
        vector<int> number(n);
        for(int i = 0 ; i<n ; i++)
        {
            doit(i , adj , distanceThreshold , number , n);
        }
        int mini = INT_MAX;
        int minindex = -1;
        for(int i = 0 ; i<number.size() ; i++)
        {
            if(number[i] <= mini)
            {
                mini = number[i];
                minindex = i;
            }
        }
        return minindex;
    }
};