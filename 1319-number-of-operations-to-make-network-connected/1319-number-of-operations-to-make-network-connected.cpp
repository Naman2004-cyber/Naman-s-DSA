class Solution {
public:
    int find(int node , vector<int> &parent){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node] , parent);
    }
    void doUnion(int parentu , int parentv , vector<int> &parent , vector<int> &rank){
        if(rank[parentu] > rank[parentv]){
            parent[parentv] = parentu;
        }
        else if(rank[parentv] > rank[parentu]){
            parent[parentu] = parentv;
        }
        else{
            parent[parentv] = parentu;
            rank[parentu]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        vector<int> parent(n);
        vector<int> rank(n , 0);
        for(int i = 0 ; i<n ; i++) parent[i] = i;
        for(int i = 0 ; i<connections.size() ; i++){
            int u = connections[i][0] , v = connections[i][1];
            int parentu = find(u , parent);
            int parentv = find(v , parent);
            if(parentu != parentv){
                doUnion(parentu , parentv , parent , rank);
            }
        }
        int components = 0;
        for(int i = 0 ; i<parent.size() ; i++) {
            if(find(i , parent) == i) components++;
        }
        return components-1;
    }
};