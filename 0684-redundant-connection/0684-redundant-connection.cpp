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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1 , 0);
        vector<int> ans;
        for(int i = 0 ; i<n+1 ; i++) parent[i] = i;
        for(int i = 0 ; i<edges.size() ; i++){
            int parentu = find(edges[i][0] , parent);
            int parentv = find(edges[i][1] , parent);
            if(parentu != parentv){
                doUnion(parentu , parentv , parent , rank);
            }
            else{
                ans = edges[i];
            }
        }
        return ans;
    }
};