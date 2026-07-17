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
    struct info{
        bool isBst;
        int sum;
        int maxi;
        int mini;
    };
    int ans = 0;
    info doit(TreeNode* node){
        if(node == NULL) return {true , 0 , INT_MIN , INT_MAX};
        info left = doit(node->left);
        info right = doit(node->right);
        if(left.isBst && right.isBst && left.maxi < node->val && right.mini > node->val){
            int sum = node->val + left.sum + right.sum;
            ans = max(ans , sum);
            return {true , sum , max(right.maxi , node->val) , min(left.mini , node->val)};
        }
        return {false , 0 , 0 , 0};
    }
    int maxSumBST(TreeNode* root) {
        doit(root);
        return ans;
    }
};