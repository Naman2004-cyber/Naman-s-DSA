class Solution {
public:
    int find(int node , vector<int> &parent){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node] , parent);
    }
    void doUnion(int parentu , int parentv , vector<int> &parent , vector<int> &rank){
        if(parentu == parentv) return;
        if(rank[parentu] > rank[parentv]){
            parent[parentv] = parentu;
        }
        else if(rank[parentv] > rank[parentu]){
            parent[parentu] = parentv;
        }
        else{
            parent[parentv] = parentu;
            rank[parentu]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for(int i = 0 ; i<26 ; i++) parent[i] = i;
        vector<int> rank(26 , 0);
        for(int i = 0 ; i<equations.size() ; i++){
            int u = equations[i][0]-'a';
            char eq = equations[i][1];
            int v = equations[i][3]-'a';
            int parentu = find(u , parent);
            int parentv = find(v , parent);
            if(eq == '='){
                doUnion(parentu , parentv , parent , rank);
            }
        }
        for(int i = 0 ; i<equations.size() ; i++){
            int u = equations[i][0]-'a';
            char eq = equations[i][1];
            int v = equations[i][3]-'a';
            int parentu = find(u , parent);
            int parentv = find(v , parent);
            if(eq == '!' && parentu == parentv) return false;
        }
        return true;
    }
};