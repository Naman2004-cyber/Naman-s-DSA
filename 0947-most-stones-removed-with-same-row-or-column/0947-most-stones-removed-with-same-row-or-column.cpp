class Solution {
public:
    void doit(int stone , vector<vector<int>>& stones , vector<int> &visited){
        visited[stone] = 1;
        for(int i = 0 ; i<stones.size() ; i++){
            if(visited[i] == 0 && (stones[stone][0] == stones[i][0] || stones[stone][1] == stones[i][1])){
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
        return stones.size()-components;
    }
};