/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void doit(TreeNode* node , vector<vector<TreeNode*>> &adj){
        if(node == NULL) return;
        if(node->left != NULL){
            adj[node->val].push_back(node->left);
            adj[node->left->val].push_back(node);
        }
        if(node->right != NULL){
            adj[node->val].push_back(node->right);
            adj[node->right->val].push_back(node);
        }
        doit(node->left , adj);
        doit(node->right , adj);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<TreeNode*>> adj(500);
        unordered_map<int , int> visited;
        doit(root , adj);
        int level = 0;
        queue<TreeNode*> qt;
        qt.push(target);
        while(!qt.empty()){
            int n = qt.size();
            vector<int> use;
            for(int i = 0 ; i<n ; i++){
                auto node = qt.front();
                qt.pop();
                visited[node->val]++;
                if(level == k) use.push_back(node->val);
                for(auto &it : adj[node->val]){
                    if(!visited[it->val]){
                        qt.push(it);
                    }
                }
            }
            if(level == k) return use;
            level++;
        }
        return {};
    }
};