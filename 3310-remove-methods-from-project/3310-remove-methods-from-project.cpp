class Solution {
public:
    void doit(int node , vector<int> &parent , int par , vector<vector<int>>& adj){
        parent[node] = par;
        for(auto &it : adj[node]){
            if(parent[it] == -1) doit(it , parent , par , adj);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i<invocations.size() ; i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> parent(n , -1);
        doit(k , parent , k , adj);
        int flag = 0;
        for(int i = 0 ; i<n ; i++){
            if(parent[i] == k) continue;
            for(auto &it : adj[i]){
                if(parent[it] == k){
                    flag = 1;
                    break;
                }
            }
        }
        vector<int> ans;
        if(flag == 1){
            for(int i = 0 ; i<n ; i++) ans.push_back(i);
            return ans;
        }
        for(int i = 0 ; i<n ; i++){
            if(parent[i] != k) ans.push_back(i);
        }
        return ans;
    }
};