class Solution {
public:
    vector<vector<long long>> distance{26 , vector<long long>(26 , LLONG_MAX)};
    void doDijkstra(int source , vector<vector<pair<int , long long>>> &adj){
        priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> pq;
        pq.push({0, source});
        distance[source][source] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long currcost = it.first;
            int currnode = it.second;
            if(currcost > distance[source][currnode]) continue;
            for(auto &a : adj[currnode]){
                int newnode = a.first;
                long long newcost = a.second;
                if(currcost + newcost < distance[source][newnode]){
                    distance[source][newnode] = currcost + newcost;
                    pq.push({distance[source][newnode] , newnode});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int , long long>>> adj(26);
        for(int i = 0 ; i<original.size() ; i++){
            adj[original[i]-'a'].push_back({changed[i]-'a' , cost[i]});
        }
        for(int i = 0 ; i<26 ; i++){
            doDijkstra(i , adj);
        }
        long long finalans = 0;
        for(int i = 0 ; i<source.size() ; i++){
            if(source[i] != target[i]){
                long long ans = distance[source[i]-'a'][target[i]-'a'];
                if(ans == LLONG_MAX) return -1;
                finalans+= distance[source[i]-'a'][target[i]-'a'];
            }
        }
        return finalans;
    }
};