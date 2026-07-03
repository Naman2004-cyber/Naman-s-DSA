class Solution {
public:
    bool check(int mid , long long k , vector<bool>& online , vector<vector<pair<int,int>>> adj , vector<int> &topoOrder)
    {
        vector<long long> distance(online.size() , LLONG_MAX);
        distance[0] = 0;
        for(int i = 0 ; i<topoOrder.size() ; i++)
        {
            int currnode = topoOrder[i];
            long long currdist = distance[currnode];
            if(currdist == LLONG_MAX) continue;
            for(auto &it : adj[currnode])
            {
                int newnode = it.first;
                long long newdist = it.second;
                if(online[newnode] == true && newdist >= mid && (newdist + currdist <= k) && (newdist + currdist < distance[newnode]))
                {
                    distance[newnode] = newdist + currdist;
                }
            }   
        }
        if(distance[online.size()-1] <= k) return true;
        return false;
    }
    void doit(vector<int> &topoOrder , vector<vector<pair<int,int>>> &adj , vector<int> &indegree)
    {
        queue<int> qt;
       for(int i = 0 ; i<indegree.size() ; i++)
       {
            if(indegree[i] == 0) qt.push(i);
       }
       while(!qt.empty())
       {
            int node = qt.front();
            qt.pop();
            topoOrder.push_back(node);
            for(auto &it : adj[node])
            {
                indegree[it.first]--;
                if(indegree[it.first] == 0) qt.push(it.first);
            }
       }
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int low = 0;
        int high = 1e9;
        int ans = -1;
        vector<vector<pair<int,int>>> adj(online.size());
         vector<int> indegree(online.size());
        for(int i = 0 ; i<edges.size() ; i++)
        {
            indegree[edges[i][1]]++;
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
        vector<int> topoOrder;
        doit(topoOrder , adj , indegree);
        while(low <= high)
        {
            int mid = high - ((high-low)/2);
            if(check(mid , k , online , adj , topoOrder))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};