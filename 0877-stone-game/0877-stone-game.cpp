class Solution {
public:
    int dp[500][500];
    int doit(int startIdx , int endIdx , vector<int>& piles){
        if(endIdx < startIdx) return 0; 
        if(dp[startIdx][endIdx] != -1) return dp[startIdx][endIdx];
        int selectStart = piles[startIdx] + min(doit(startIdx+2 , endIdx , piles) , doit(startIdx+1 , endIdx-1 , piles));
        int selectEnd = piles[endIdx] + min(doit(startIdx , endIdx-2 , piles) , doit(startIdx+1 , endIdx-1 , piles));
        return dp[startIdx][endIdx]= max(selectStart , selectEnd);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = accumulate(piles.begin() , piles.end() , 0);
        memset(dp , -1 , sizeof(dp));
        int aliceScore = doit(0 , n-1 , piles);
        int bobScore = total - aliceScore;
        if(aliceScore > bobScore) return true;
        return false;
    }
};