class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        vector<vector<int>> adj(parent.size());
        for(int i = 1 ; i<parent.size() ; i++){
            adj[parent[i]].push_back(i);
        }
        int index = 0;
        int height = 0;
        queue<int> qt;
        qt.push(0);
        while(!qt.empty()){
            int n = qt.size();
            for(int i = 0 ; i<n ; i++){
                auto it = qt.front();
                qt.pop();
                for(auto &a : adj[it]){
                    qt.push(a);
                }
            }
            height++;
        }
        long long ans = 0;
        queue<int> qit;
        qit.push(0);
        int level = 1;
        while(!qit.empty()){
            int n = qit.size();
            for(int i = 0 ; i<n ; i++){
                auto it = qit.front();
                qit.pop();
                ans = ans + (1LL * nums[it] * (height - level + 1));
                for(auto &a : adj[it]){
                    qit.push(a);
                }
            }
            level++;
        }
        return ans;
    }
};