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
    int maxi = INT_MIN;
    int doit(TreeNode* node){
        if(node == NULL) return 0;
        int left = max(0 , doit(node->left));
        int right = max(0 , doit(node->right));
        maxi = max(maxi , left + right + node->val);
        return node->val + max(left , right);
    }
    int maxPathSum(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return root->val;
        doit(root);
        return maxi;
    }
};