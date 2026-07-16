class Solution {
public:
    void doit(int index , vector<vector<int>>& stones , vector<int> &visited){
        visited[index] = 1;
        for(int i = 0 ; i<stones.size() ; i++){
            if(visited[i] == 0 && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1])){
                doit(i , stones , visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
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