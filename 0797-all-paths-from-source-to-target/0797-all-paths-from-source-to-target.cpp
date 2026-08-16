class Solution {
public:
    void doit(int node , vector<vector<int>>& graph , vector<int> &use , vector<vector<int>> &ans){
        if(node == graph.size()-1){
            ans.push_back(use);
        }
        for(auto &it : graph[node]){
            use.push_back(it);
            doit(it , graph , use , ans);
            use.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> use;
        vector<vector<int>> ans;
        use.push_back(0);
        doit(0 , graph , use , ans);
        return ans;
    }
};