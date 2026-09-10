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
    int count = 0;
    pair<int , int> doit(TreeNode* node){
        if(node == NULL) return {0 , 0};
        pair<int , int> left = doit(node->left);
        pair<int , int> right = doit(node->right);
        int n = 1 + left.second + right.second;
        int sum = left.first + right.first + node->val;
        if((sum/n) == node->val) count++;
        return {sum , n};
    }
    int averageOfSubtree(TreeNode* root) {
        doit(root);
        return count;
    }
};