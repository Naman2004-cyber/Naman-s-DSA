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
    pair<int , int> doit(TreeNode* root , int &count){
        if(root == NULL) return {0 , 0};
        pair<int , int> left = doit(root->left , count);
        pair<int , int> right = doit(root->right , count);
        int sum = left.first + right.first + root->val;
        int total = left.second + right.second + 1;
        if((sum/total) == root->val) count++;
        return {sum , total};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        doit(root , count);
        return count;
    }
};