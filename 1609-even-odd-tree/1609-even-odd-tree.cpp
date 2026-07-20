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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> qt;
        qt.push(root);
        int level = 0;
        while(!qt.empty()){
            int n = qt.size();
            int prev = -1;
            for(int i = 0 ; i<n ; i++){
                TreeNode* node = qt.front();
                qt.pop();
                if(level%2 == 0 && node->val%2 == 0) return false;
                if(level%2 != 0 && node->val%2 != 0) return false;
                if(prev != -1){
                    if(level%2 == 0){
                        if(node->val <= prev) return false;
                    }
                    if(level%2 != 0){
                        if(node->val >= prev) return false;
                    }
                }
                prev = node->val;
                if(node->left != NULL) qt.push(node->left);
                if(node->right != NULL) qt.push(node->right);
            }
            level++;
        }
        return true;
    }
};