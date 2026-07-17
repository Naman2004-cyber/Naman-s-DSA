/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> finalans;
        vector<int> ans;
        queue<Node*> qt;
        qt.push(root);
        while(!qt.empty()){
            int n = qt.size();
            for(int i = 0 ; i<n ; i++){
                Node* node = qt.front();
                qt.pop();
                ans.push_back(node->val);
                int a = (node->children).size();
                for(int j = 0 ; j<a ; j++){
                    qt.push(node->children[j]);
                }
            }
            finalans.push_back(ans);
            ans.clear();
        }
        return finalans;
    }
};