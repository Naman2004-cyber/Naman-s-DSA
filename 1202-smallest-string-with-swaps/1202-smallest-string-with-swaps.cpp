class Solution {
public:
    int findParent(int node , vector<int>& parent){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node] , parent);
    }
    void doUnion(int u , int v , vector<int>& parent , vector<int> &rank){
        int parentu = findParent(u , parent);
        int parentv = findParent(v , parent);
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> parent(s.size());
        for(int i = 0 ; i<s.size() ; i++) parent[i] = i;
        vector<int> rank(s.size() , 0);
        for(int i = 0 ; i<pairs.size() ; i++){
            doUnion(pairs[i][0] , pairs[i][1] , parent , rank);
        }
        unordered_map<int , string> mpp;
        unordered_map<int , int> konParent;
        for(int i = 0 ; i<s.size() ; i++){
            int component = findParent(i , parent);
            mpp[component]+=s[i];
            konParent[i] = component;
        }
        for(auto &it : mpp){
            sort(it.second.begin() , it.second.end());
        }
        unordered_map<int , int> ptr;
        for(int i = 0 ; i<s.size() ; i++){
            int component = konParent[i];
            s[i] = mpp[component][ptr[component]];
            ptr[component]++;
        }
        return s;
    }
};