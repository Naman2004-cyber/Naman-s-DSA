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
class FindElements {
public:
    unordered_set<int> st;
    void doit(TreeNode* node){
        if(node == NULL) return;
        if(node->left != NULL){
            node->left->val = 2*node->val + 1;
            st.insert(node->left->val);
        }
        if(node->right != NULL){
            node->right->val = 2*node->val + 2;
            st.insert(node->right->val);
        }
        doit(node->left);
        doit(node->right);
    }
    // bool pataKaro(TreeNode* node , int target){
    //     if(node == NULL) return false;
    //     if(node->val == target) return true;
    //     return pataKaro(node->left , target) || pataKaro(node->right , target);
    // }
    TreeNode* use;
    FindElements(TreeNode* root) {
        use = root;
        root->val = 0;
        st.insert(root->val);
        doit(root);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */