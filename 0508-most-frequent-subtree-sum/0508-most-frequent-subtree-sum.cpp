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
    int doit(TreeNode* node , unordered_map<int , int> &mpp , int &maxi){
        if(node == NULL) return 0;
        int left = doit(node->left , mpp , maxi);
        int right = doit(node->right , mpp , maxi);
        int sum = node->val + left + right;
        mpp[sum]++;
        maxi = max(maxi , mpp[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int , int> mpp;
        int maxi = 0;
        doit(root , mpp , maxi);
        vector<int> ans;
        for(auto& it : mpp){
            if(maxi == it.second) ans.push_back(it.first);
        }
        return ans;
    }
};