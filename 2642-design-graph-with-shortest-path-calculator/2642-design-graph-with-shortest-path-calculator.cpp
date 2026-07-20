class Graph {
public:
    vector<vector<int>> useEdges;
    int size;
    Graph(int n, vector<vector<int>>& edges) {
        useEdges = edges;
        size = n;
    }
    void addEdge(vector<int> edge) {
        useEdges.push_back(edge);
    }
    int shortestPath(int node1, int node2) {
        vector<vector<pair<int , int>>> adj(size);
        for(int i = 0 ; i<useEdges.size() ; i++){
            adj[useEdges[i][0]].push_back({useEdges[i][1] , useEdges[i][2]});
        }
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        vector<int> distance(size , INT_MAX);
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