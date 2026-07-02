class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(int i = 0 ; i<edges.size() ; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> minTime(n+1 , 1e9);
        vector<int> secondmintime(n+1 , 1e9);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,1});
        minTime[1]= 0;
        secondmintime[1]= 1e9;
        int count = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currtime = it.first;
            int currnode = it.second;
            // now there will be waiting time from time node to other node on the basis of whether signal is green or red
            // divide currtime by change , if even means green and if odd means red
            if(currtime > secondmintime[currnode]) continue;
            if(currnode == n && currtime == secondmintime[currnode]) return currtime;
            int waiting = 0;
            int val = currtime/change;
            if(val%2 != 0)
            {
                // when green 
                int whengreen = change * (val+1);
                waiting = whengreen - currtime;
            }
            // if(currnode == n)
            // {
            //     if(currtime > minTime[currnode]) return currtime;

            // }
            // if(currtime > minTime[currnode]) continue;
            for(auto &a : adj[currnode])
            {
                int newnode = a;
                int newtime = currtime+waiting+time;
                if(newtime < minTime[newnode])
                {
                    int store = minTime[newnode];
                    minTime[newnode] = newtime;
                    pq.push({minTime[newnode] , newnode});
                    secondmintime[newnode] = store;
                    pq.push({secondmintime[newnode] , newnode});
                }
                else if(newtime > minTime[newnode] && newtime < secondmintime[newnode])
                {
                    secondmintime[newnode] = newtime;
                    pq.push({secondmintime[newnode] , newnode});
                }
            }
        }
        return -1;
    }
};