class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        // first of all form the adjaceny list which contains the children of each node and the values of the children
        vector<vector<pair<int , int>>> adj(parent.size());
        for(int i = 1 ; i<parent.size() ; i++){
            adj[parent[i]].push_back({i , nums[i]});
        }
        int index = 0;
        // for(auto &it : adj){
        //     cout << index << " ---> ";
        //     for(auto &a : it){
        //         cout << a.first << "," << a.second << " ";
        //     }
        //     cout << endl;
        //     index++;
        // }
        // find the height of the tree
        int height = 0;
        queue<int> qt;
        qt.push(0);
        while(!qt.empty()){
            int n = qt.size();
            for(int i = 0 ; i<n ; i++){
                auto it = qt.front();
                qt.pop();
                for(auto &a : adj[it]){
                    qt.push(a.first);
                }
            }
            height++;
        }
        long long ans = 0;
        queue<pair<int , int>> qit;
        qit.push({0 , nums[0]});
        int level = 1;
        while(!qit.empty()){
            int n = qit.size();
            for(int i = 0 ; i<n ; i++){
                auto it = qit.front();
                qit.pop();
                ans = ans + (1LL * it.second * (height - level + 1));
                for(auto &a : adj[it.first]){
                    qit.push(a);
                }
            }
            level++;
        }
        return ans;
    }
};