class Solution {
public:
    struct Node{
        int len;
        int best;
        int pref;
        int suff;
        char pref_char;
        char suff_char;
    };
    Node merge(Node left , Node right){
        Node parent;
        parent.len = left.len + right.len;
        parent.pref_char = left.pref_char;
        parent.suff_char = right.suff_char;
        parent.best = max(left.best , right.best);
        if(left.suff_char == right.pref_char){
            parent.best = max(parent.best , left.suff + right.pref);
        }
        parent.pref = left.pref;
        if((left.pref == left.len) && (left.suff_char == right.pref_char)){
            parent.pref = left.pref + right.pref;
        }
        parent.suff = right.suff;
        if((right.suff == right.len) && (right.pref_char == left.suff_char)){
            parent.suff = right.suff + left.suff;
        }
        return parent;
    }
    void buildTree(int segIdx , int l , int r , vector<Node> &segTree , string &s){
        if(l == r){
            segTree[segIdx] = {1,1,1,1,s[l],s[l]};
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*segIdx+1 , l , mid , segTree , s);
        buildTree(2*segIdx+2 , mid+1 , r , segTree , s);
        segTree[segIdx] = merge(segTree[2*segIdx+1] , segTree[2*segIdx+2]);
    }
    void updateTree(int segIdx , int l , int r , int idx , char val , vector<Node>& segTree , string &s){
        if(l == r) {
            segTree[segIdx] = {
                1,
                1,
                1,
                1,
                val,
                val
            };
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid){
            updateTree(2*segIdx+1 , l , mid , idx , val , segTree , s);
        }
        else{
            updateTree(2*segIdx+2 , mid+1 , r , idx , val , segTree , s);
        }

        segTree[segIdx] = merge(segTree[2*segIdx+1] , segTree[2*segIdx+2]);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        vector<Node> segTree(4*n);
        buildTree(0 , 0 , n-1 , segTree , s);
        vector<int> ans;
        for(int i = 0 ; i<queryIndices.size() ; i++){
            int idx = queryIndices[i];
            char ch = queryCharacters[i];
            updateTree(0, 0, n - 1, idx, ch , segTree , s);
            ans.push_back(segTree[0].best);
        }
        return ans;
    }
};