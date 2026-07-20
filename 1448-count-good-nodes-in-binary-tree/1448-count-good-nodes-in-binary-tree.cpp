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
    void doit(TreeNode* node , int maxi){
        if(node == NULL) return;
        if(node->val >= maxi){
            maxi = node->val;
            count++;
        }
        doit(node->left , maxi);
        doit(node->right , maxi);
    }
    int goodNodes(TreeNode* root) {
        doit(root , INT_MIN);
        return count;
    }
};