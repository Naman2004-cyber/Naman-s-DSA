class Solution {
public:
    bool doit(int mid , long long k , vector<bool>& online , vector<vector<pair<int,int>>> &adj)
    {
        vector<long long> mincost(online.size() , LLONG_MAX);
        priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;
        pq.push({0 , 0});
        mincost[0] = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long currcost = it.first;
            int currnode = it.second;
            if(currcost > mincost[currnode]) continue;
            if(currnode == online.size()-1) return true;
            for(auto &a : adj[currnode])
            {
                int newnode = a.first;
                long long newcost = a.second;
                if(online[newnode] == true && newcost >= mid && (newcost + currcost)<=k && (newcost + currcost < mincost[newnode]))
                {
                    mincost[newnode] = newcost + currcost;
                    pq.push({mincost[newnode] , newnode});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int low = 0;
        int high = 1e9;
        int ans = -1;
        vector<vector<pair<int,int>>> adj(online.size());
        for(int i = 0 ; i<edges.size() ; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
        while(low <= high)
        {
            int mid = high - ((high-low)/2);
            if(doit(mid , k , online , adj))
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