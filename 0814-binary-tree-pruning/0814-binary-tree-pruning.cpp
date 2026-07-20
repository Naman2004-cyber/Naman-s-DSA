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
    int doit(TreeNode* node){
        // if(node == NULL) 
        if(node == NULL) return 0;
        if(node->left == NULL && node->right == NULL){
            if(node->val == 1) return 1;
            return 0;
        }
        int left = doit(node->left);
        int right = doit(node->right);
        if(left == 0) node->left = NULL;
        if(right == 0) node->right = NULL;
        if(node->val == 1 || left == 1 || right == 1) return 1;
        else return 0;
    }
    TreeNode* pruneTree(TreeNode* root) {
        int use = doit(root);
        if(use == 0) return NULL;
        return root;
    }
};