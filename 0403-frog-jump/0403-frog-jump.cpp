class Solution {
public:
    int dp[2001][2001];
    unordered_map<int , int> posToIdx;
    bool doit(int idx , int prevJump , vector<int>& stones){
        if(idx == stones.size()-1) return true;
        if(dp[idx][prevJump] != -1) return dp[idx][prevJump];
        bool prev_minus = false;
        bool prev_equal = false;
        bool prev_plus = false;
        if(prevJump-1 > 0){
            int newPos = stones[idx] + prevJump - 1;
            if(posToIdx.find(newPos) != posToIdx.end()){
                prev_minus = doit(posToIdx[newPos] , prevJump - 1 , stones);
            }
        }
        if(prevJump > 0){
            int newPos = stones[idx] + prevJump;
            if(posToIdx.find(newPos) != posToIdx.end()){
                prev_equal = doit(posToIdx[newPos] , prevJump , stones);
            }
        }
        if(prevJump+1 > 0){
            int newPos = stones[idx] + prevJump + 1;
            if(posToIdx.find(newPos) != posToIdx.end()){
                prev_plus = doit(posToIdx[newPos] , prevJump +1 , stones);
            }
        }
        return dp[idx][prevJump] = prev_minus || prev_equal || prev_plus;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        for(int i = 0 ; i<stones.size() ; i++) posToIdx[stones[i]] = i;
        memset(dp , -1 , sizeof(dp));
        return doit(1 , 1 , stones);
    }
};