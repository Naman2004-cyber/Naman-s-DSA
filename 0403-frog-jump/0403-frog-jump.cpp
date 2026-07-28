class Solution {
public:
    bool dp[2001][2001];
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
        int n = stones.size();
        unordered_map<int , int> posToIdx;
        for(int i = 0 ; i<n ; i++) posToIdx[stones[i]] = i;
        memset(dp , false , sizeof(dp));
        dp[1][1] = 1;
        for(int idx = 1 ; idx<n ; idx++){
            for(int prevJumps = 1 ; prevJumps <= n ; prevJumps++){
                if(!dp[idx][prevJumps]) continue;
                if(prevJumps-1 > 0){
                    int newPos1 = stones[idx] + prevJumps - 1;
                    if(posToIdx.find(newPos1) != posToIdx.end()) dp[posToIdx[newPos1]][prevJumps-1] = true;
                }

                int newPos2 = stones[idx] + prevJumps;
                if(posToIdx.find(newPos2) != posToIdx.end()) dp[posToIdx[newPos2]][prevJumps] = true;

                int newPos3 = stones[idx] + prevJumps + 1;
                if(posToIdx.find(newPos3) != posToIdx.end()) dp[posToIdx[newPos3]][prevJumps+1] = true;
            }
        }
        for(int jumps = 1 ; jumps <= n ; jumps++){
            if(dp[n-1][jumps]) return true;
        }
        return false;
    }
};