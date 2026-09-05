class Solution {
public:
    int findParent(int node , vector<int>& parent){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node] , parent);
    }
    void doUnion(int u , int v , vector<int>& parent , vector<int>& rank){
        int parentu = findParent(u , parent);
        int parentv = findParent(v , parent);
        if(rank[parentu] > rank[parentv]){
            parent[parentv] = parentu;
        }
        else if(rank[parentv] > rank[parentu]){
            parent[parentu] = parentv;
        }
        else{
            rank[parentu]++;
            parent[parentv] = parentu;
        }
    }
    int r[4] = {0 , 1 , 0 , -1} , c[4] = {1 , 0 , -1 , 0};
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<int> parent(cells.size()+2);
        vector<int> landOrNot(cells.size()+2 , 0);
        vector<int> rank(cells.size()+2 , 0);
        for(int i = 0 ; i<parent.size() ; i++) parent[i] = i;
        for(int i = cells.size()-1 ; i>=0 ; i--){
            int currx = cells[i][0] -1 , curry = cells[i][1] - 1;
            int cell = currx*col + curry;
            landOrNot[cell] = 1;
            if(currx == 0) doUnion(cell , cells.size() , parent , rank);
            if(currx == row-1) doUnion(cell , cells.size()+1 , parent , rank);
            for(int j = 0 ; j<4 ; j++){
                int newx = currx + r[j] , newy = curry + c[j];
                if(newx <0 || newy < 0 || newx >=row || newy >= col) continue;
                int newCell = newx*col + newy;
                if(landOrNot[newCell] == 0) continue;
                doUnion(cell , newCell , parent , rank);
            }
            if(findParent(cells.size(), parent) == findParent(cells.size()+1 , parent)) return i;
        }
        // for(int i = 0 ; i<parent.size() ; i++) cout << parent[i] << " ";
        return 0;
    }
};