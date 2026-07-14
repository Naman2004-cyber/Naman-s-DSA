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
        else
        {
            parent[parentv] = parentu;
            rank[parentu]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n , 0);
        for(int i = 0 ; i<parent.size() ; i++) parent[i] = i;
        for(int i = 0 ; i<edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int parentu = find(u , parent);
            int parentv = find(v , parent);
            if(parentu != parentv){
                doUnion(parentu , parentv , parent , rank);
            }
        }
        unordered_map<int,int> mpp;
        for(int i = 0 ; i<n ; i++){
            find(i , parent);
            mpp[parent[i]]++;
        }
        long long total = 0;
        for(auto &it : mpp){
            total+=it.second;
        }
        long long ans = 0;
        for(auto &it : mpp){
            long long first = it.second;
            total-=it.second;
            long long second = total;
            ans = ans + (1LL * first *second);
        }
        return ans;
    }
};