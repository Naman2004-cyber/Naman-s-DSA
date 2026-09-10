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
    pair<int , int> doit(TreeNode* node , int limit , int sum){
        if(node == NULL) return {0 , 0};
        pair<int , int> left = doit(node->left , limit , sum + node->val);
        pair<int , int> right = doit(node->right , limit , sum + node->val);
        int final = 0;
        if(node->left != NULL && node->right != NULL){
            final = max(left.second , right.second) + node->val;
        }
        else if(node->left != NULL) final = left.second + node->val;
        else if(node->right != NULL) final = right.second + node->val;
        else final = node->val;
        if(left.first == 1) node->left = NULL;
        if(right.first == 1) node->right = NULL;
        if(final+sum < limit) return {1 , final};
        return {0 , final};
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        pair<int , int> dekho = doit(root , limit , 0);
        if(dekho.first == 1) return NULL;
        return root;
    }
};