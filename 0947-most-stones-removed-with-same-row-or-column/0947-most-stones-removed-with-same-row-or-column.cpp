class Solution {
public:
    unordered_map<int , vector<int>> rows;
    unordered_map<int , vector<int>> columns;
    void doit(int index , vector<vector<int>>& stones , vector<int> &visited){
        visited[index] = 1;
        int r = stones[index][0];
        int c = stones[index][1];
        auto rowList = rows[r];
        rows.erase(r);
        for(auto &it : rowList){
            if(visited[it] == 0){
                doit(it , stones , visited);
            }
        }
        auto colList = columns[c];
        columns.erase(c);
        for(auto &it : colList){
            if(visited[it] == 0){
                doit(it , stones , visited);
            }
        }
        columns.erase(stones[index][1]);
    }
    int removeStones(vector<vector<int>>& stones) {
        for(int i = 0 ; i<stones.size() ; i++){
            rows[stones[i][0]].push_back(i);
            columns[stones[i][1]].push_back(i);
        }
        vector<int> visited(stones.size() , 0);
        int components = 0;
        for(int i = 0 ; i<stones.size() ; i++){
            if(visited[i] == 0){
                doit(i , stones , visited);
                components++;
            }
        }
        return stones.size() - components;
    }
};