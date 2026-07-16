class Solution {
public:
    unordered_map<int , vector<int>> rows;
    unordered_map<int , vector<int>> columns;
    void doit(int index , vector<vector<int>>& stones , vector<int> &visited){
        visited[index] = 1;
        for(auto &it : rows[stones[index][0]]){
            if(visited[it] == 0){
                doit(it , stones , visited);
            }
        }
        for(auto &it : columns[stones[index][1]]){
            if(visited[it] == 0){
                doit(it , stones , visited);
            }
        }
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