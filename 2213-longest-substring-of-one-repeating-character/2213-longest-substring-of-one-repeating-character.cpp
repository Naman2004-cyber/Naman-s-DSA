class Solution {
public:
    struct Node{
        int len;
        int best;
        int pref;
        int suff;
        char pref_ch;
        char suff_ch;
    };
    Node merge(Node left , Node right){
        Node parent;
        parent.len = left.len + right.len;
        parent.pref_ch = left.pref_ch;
        parent.suff_ch = right.suff_ch;
        parent.best = max(left.best , right.best);
        if(left.suff_ch == right.pref_ch){
            parent.best = max(parent.best , left.suff + right.pref);
        }
        parent.pref = left.pref;
        if(left.len == left.pref && left.suff_ch == right.pref_ch){
            parent.pref = left.pref + right.pref;
        }
        parent.suff = right.suff;
        if(right.suff == right.len && right.pref_ch == left.suff_ch){
            parent.suff = right.suff + left.suff;
        }
        return parent;
    }
    void buildTree(int segIdx , int l , int r , vector<Node> &segTree , string &s){
        if(l == r){
            segTree[segIdx] = {
                1,
                1,
                1,
                1,
                s[l],
                s[l]
            };
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*segIdx+1 , l , mid , segTree , s);
        buildTree(2*segIdx+2 , mid+1 , r , segTree , s);
        segTree[segIdx] = merge(segTree[2*segIdx+1]  , segTree[2*segIdx+2]);
    }
    void updateTree(int segIdx , int l , int r , int idx , char ch , vector<Node> &segTree , string &s){
        if(l == r){
            segTree[segIdx] = {
                1,
                1,
                1,
                1,
                ch,
                ch
            };
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid){
            updateTree(2*segIdx+1 , l , mid , idx , ch , segTree , s);
        }
        else{
            updateTree(2*segIdx+2 , mid+1 , r , idx , ch , segTree , s);
        }
        segTree[segIdx] = merge(segTree[2*segIdx+1] , segTree[2*segIdx+2]);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        vector<Node> segTree(4*n);
        buildTree(0 , 0 , n-1 , segTree , s);
        vector<int> ans;
        for(int i = 0 ; i<queryCharacters.size() ; i++){
            updateTree(0 , 0 , n-1 , queryIndices[i] , queryCharacters[i] , segTree , s);
            ans.push_back(segTree[0].best);
        }
        return ans;
    }
};