class Graph {
public:
    vector<vector<pair<int , int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(int i = 0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
    }
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1] , edge[2]});
    }
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        vector<int> distance(adj.size() , INT_MAX);
        distance[node1] = 0;
        pq.push({0 , node1});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int currnode = it.second;
            int currcost = it.first;
            if(currcost > distance[currnode]) continue;
            if(currnode == node2) return currcost;
            for(auto &a : adj[currnode]){
                int newnode = a.first;
                int newcost = a.second;
                if(currcost + newcost < distance[newnode]){
                    distance[newnode] = currcost + newcost;
                    pq.push({distance[newnode] , newnode});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */