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
    void doit(TreeNode* node , int mini , int maxi , int &ans){
        if(node == NULL) return;
        ans = max(ans , max(abs(maxi - node->val) , abs(mini - node->val)));
        doit(node->left , min(node->val , mini) , max(node->val , maxi) , ans);
        doit(node->right , min(node->val , mini) , max(node->val , maxi) , ans);
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini = root->val;
        int maxi = root->val;
        int ans = INT_MIN;
        doit(root , mini , maxi , ans);
        return ans;
    }
};