class Solution {
public:
    void doit(int node , vector<vector<int>> &adj , vector<int> &visited , int &count , unordered_set<int> &st){
        visited[node] = 1;
        count++;
        for(auto &it : adj[node]){
            if(visited[it] == 0 && st.count(it) == 0){
                doit(it , adj , visited , count , st);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i<edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> st;
        st.insert(restricted.begin() , restricted.end());
        vector<int> visited(n , 0);
        int count = 0;
        doit(0 , adj , visited , count , st);
        return count;
    }
};