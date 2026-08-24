class Solution {
public:
    char findParent(char node , vector<char>& parent){
        if(parent[node-'a'] == node) return node;
        return parent[node-'a'] = findParent(parent[node-'a'] , parent);
    }
    void doUnion(char u , char v , vector<char>& parent){
        char parentU = findParent(u , parent);
        char parentV = findParent(v , parent);
        if(parentU == parentV) return;
        if(parentU < parentV){
            parent[parentV-'a'] = parentU;
        }
        else{
            parent[parentU-'a'] = parentV;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char> parent(26);
        for(int i = 0 ; i<26 ; i++) parent[i] = 'a' + i;
        for(int i = 0 ; i<s1.size() ; i++){
            doUnion(s1[i] , s2[i] , parent);
        }
        string ans = "";
        for(int i = 0 ; i<baseStr.size() ; i++){
            ans+=findParent(baseStr[i] , parent);
        }
        return ans;
    }
};