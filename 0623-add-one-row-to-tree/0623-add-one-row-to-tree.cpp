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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newnode = new TreeNode(val);
            newnode->left = root;
            newnode->right = NULL;
            return newnode;
        }
        int level = 1;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty()){
            int n = qt.size();
            for(int i = 0 ; i<n ; i++){
                TreeNode* node = qt.front();
                qt.pop();
                if(level == depth-1){
                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);
                    TreeNode* storeLeft = node->left;
                    TreeNode* storeRight = node->right;
                    node->left = newLeft;
                    newLeft->left = storeLeft;
                    node->right = newRight;
                    newRight->right = storeRight;
                }
                else
                {
                    if(node->left != NULL) qt.push(node->left);
                    if(node->right != NULL) qt.push(node->right);
                }
            }
            level++;
        }
        return root;
    }
};