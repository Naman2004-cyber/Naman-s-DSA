class Solution {
public:
    int dp[20][20];
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            for(int j = i-1 ; j>=0 ; j--){
                if(j < i) dp[i][j] = 0;
            }
        }
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = 0 ; j<n ; j++){
                if(j < i) continue;
                int startSe = 0;
                if(i+1 < n) startSe = nums[i] - dp[i+1][j];
                int endSe = 0;
                if(j-1 >= 0) endSe = nums[j] - dp[i][j-1];
                dp[i][j] = max(startSe , endSe);
            }
        }
        if(dp[0][n-1] >= 0) return true;
        return false;
    }
};