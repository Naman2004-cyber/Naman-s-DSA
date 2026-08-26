class Solution {
public:
    static bool cmp(const vector<int>&a , const vector<int>& b){
        return a[0] > b[0];
    }
    int findParent(int node , vector<int>&parent){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node] , parent);
    }
    void doUnion(int u , int v , vector<int>& parent){
        int parentU = findParent(u , parent);
        int parentV = findParent(v , parent);
        if(parentU == parentV) return;
        if(parentU < parentV){
            parent[parentV] = parentU;
        }
        else{
            parent[parentU] = parentV;
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parentA(n+1);
        vector<int> parentB(n+1);
        vector<int> rankA(n+1 , 0);
        vector<int> rankB(n+1 , 0);
        for(int i = 0 ; i<=n ; i++){
            parentA[i] = i;
            parentB[i] = i;
        }
        int count = 0;
        sort(edges.begin() , edges.end() , cmp);
        for(int i = 0 ; i<edges.size() ; i++){
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
            if(type == 1){
                int parentU = findParent(u , parentA);
                int parentV = findParent(v , parentA);
                if(parentU == parentV){
                    count++;
                }
                else{
                    doUnion(u , v , parentA);
                }
            }
            else if(type == 2){
                int parentU = findParent(u , parentB);
                int parentV = findParent(v , parentB);
                if(parentU == parentV){
                    count++;
                }
                else{
                    doUnion(u , v , parentB);
                }
            }
            else if(type == 3){
                int parentU_A = findParent(u , parentA);
                int parentV_A = findParent(v , parentA);
                int parentU_B = findParent(u , parentB);
                int parentV_B = findParent(v , parentB);
                if((parentU_A == parentV_A) && (parentU_B == parentV_B)){
                    count++;
                }
                else if((parentU_A != parentV_A) && (parentU_B != parentV_B)){
                    doUnion(u , v , parentA);
                    doUnion(u , v , parentB);
                }
                else if(parentU_A != parentV_A){
                    doUnion(u , v , parentA);
                }
                else if(parentU_B != parentV_B){
                    doUnion(u , v , parentB);
                }
            }
        }
        int countParentA = parentA[1];
        int countParentB = parentB[1];
        for(int i = 2 ; i<parentA.size() ; i++){
            if(findParent(parentA[i] , parentA) != countParentA || findParent(parentB[i] , parentB) != countParentB) return -1;
        }
        return count;
    }
};