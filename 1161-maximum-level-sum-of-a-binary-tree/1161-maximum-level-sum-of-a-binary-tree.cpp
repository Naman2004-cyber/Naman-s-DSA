/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxlevel = 0;
        int level = 1;
        long long maxsum = INT_MIN;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int n = qt.size();
            long long sum = 0;
            for(int i = 0 ; i<n ; i++){
                TreeNode* node = qt.front();
                qt.pop();
                sum+=node->val;
                if(node->left != NULL) qt.push(node->left);
                if(node->right != NULL) qt.push(node->right);
            }
            if(sum > maxsum){
                maxsum = sum;
                maxlevel = level;
            }
            level++;
        }
        return maxlevel;
    }
};