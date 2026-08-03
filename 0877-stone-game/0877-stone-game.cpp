class Solution {
public:
    int dp[500][500];
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int total = accumulate(piles.begin() , piles.end() , 0);
        for(int i = 0 ; i<n ; i++){
            dp[i][i] = piles[i];
        }
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = 0 ; j<n ; j++){
                if(j < i || i == j) continue;
                int startFirstChoice = i+2<n ? dp[i+2][j] : INT_MAX;
                int startSecondChoice = i+1<n && j-1>=0 ? dp[i+1][j-1] : INT_MAX;
                int selectStart = piles[i] + min(startFirstChoice ,startSecondChoice);

                int endFirstChoice = j-2>=0 ? dp[i][j-2] : INT_MAX;
                int endSecondChoice = i+1 < n && j-1 >=0 ? dp[i+1][j-1] : INT_MAX;
                int selectEnd = piles[j] + min(endFirstChoice , endSecondChoice);

                dp[i][j] = max(selectStart , selectEnd);
            }
        }
        int aliceScore = dp[0][n-1];
        int bobScore = total - aliceScore;
        if(aliceScore > bobScore) return true;
        return false;
    }
};