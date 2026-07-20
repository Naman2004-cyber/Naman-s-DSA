class Solution {
public:
    vector<vector<long long>> distance{26 , vector<long long>(26 , LLONG_MAX)};
    void doit(int source , vector<vector<pair<int,long long>>> &adj){
        priority_queue<pair<long long , int> , vector<pair<long long,int>> , greater<pair<long long ,int>>> pq;
        distance[source][source] = 0;
        pq.push({0 , source});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long currcost = it.first;
            int currnode = it.second;
            if(currcost > distance[source][currnode]) continue;
            for(auto &it : adj[currnode]){
                int newnode = it.first;
                long long newcost = it.second;
                if(newcost + currcost < distance[source][newnode]){
                    distance[source][newnode] = newcost + currcost;
                    pq.push({currcost + newcost , newnode});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,long long >>> adj(26);
        for(int i = 0 ; i<original.size() ; i++){
            adj[original[i]-'a'].push_back({changed[i]-'a' , cost[i]});
        }
        //dijkstra on each character which is not equal
        for(int i = 0 ; i<26 ; i++){
            doit(i , adj);
        }
        long long finalans = 0;
        for(int i = 0 ; i<source.size() ; i++){
            if(source[i] != target[i]){
                if(distance[source[i]-'a'][target[i]-'a'] == LLONG_MAX) return -1;
                finalans = finalans + distance[source[i]-'a'][target[i]-'a'];
            }
        }
        return finalans;
    }
};