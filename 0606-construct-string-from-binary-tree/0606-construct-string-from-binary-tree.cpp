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
    string doit(TreeNode* node){
        if(node == NULL) return "";
        if(node->left == NULL && node->right == NULL){
            string final = "";
            final+=to_string(node->val);
            return final;
        } 
        string left = doit(node->left);
        string right = doit(node->right);
        string use = "";
        use+=to_string(node->val);
        if(left == ""){
            use+="()";
        }
        if(left != ""){
            use+="(";
            use+=left;
            use+=")";
        }
        if(right != ""){
            use+="(";
            use+=right;
            use+=")";
        }
        return use;
    }
    string tree2str(TreeNode* root) {
        return doit(root);
    }
};