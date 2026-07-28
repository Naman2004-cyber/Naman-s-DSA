/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> qt;
        qt.push(root);
        while(!qt.empty()){
            vector<Node*> use;
            int n = qt.size();
            for(int i = 0 ; i<n ; i++){
                Node* node = qt.front();
                qt.pop();
                use.push_back(node);
                if(node->left != NULL) qt.push(node->left);
                if(node->right != NULL) qt.push(node->right);
            }
            for(int i = 0 ; i<n-1 ; i++){
                use[i]->next = use[i+1];
            }
        }
        return root;
    }
};