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
    long long prev = LLONG_MIN;
    bool doit(TreeNode* node){
        if(node == NULL) return true;
        bool left = doit(node->left);
        if(node->val <= prev) return false;
        prev = node->val;
        bool right = doit(node->right);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        return doit(root);
    }
};