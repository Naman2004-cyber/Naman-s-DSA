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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> qt;
        qt.push(root);
        int finalcount = 0;
        while(!qt.empty()){
            int n = qt.size();
            vector<int> arr;
            for(int i = 0 ; i<n ; i++){
                TreeNode* node = qt.front();
                qt.pop();
                arr.push_back(node->val);
                if(node->left != NULL) qt.push(node->left);
                if(node->right != NULL) qt.push(node->right);
            }
            vector<int> sorted = arr;
            sort(sorted.begin() , sorted.end());
            unordered_map<int , int> mpp;
            for(int i = 0 ; i<sorted.size() ; i++) mpp[sorted[i]] = i;
            while(true){
                int flag = 0;
                for(int i = 0 ; i<arr.size() ; i++){
                    if(arr[i] != sorted[i]){
                        flag = 1;
                        finalcount++;
                        swap(arr[i] , arr[mpp[arr[i]]]);
                    }
                }
                if(flag == 0) break;
            }
        }
        return finalcount;
    }
};