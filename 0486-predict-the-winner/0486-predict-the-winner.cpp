class Solution {
public:
    int dp[20][20];
    int doit(int startIdx , int endIdx , vector<int>& nums){
        if(startIdx > endIdx) return 0;
        if(dp[startIdx][endIdx] != -1) return dp[startIdx][endIdx];
        int startSe = nums[startIdx] + min(doit(startIdx+2 , endIdx , nums) , doit(startIdx+1 , endIdx-1 , nums));
        int endSe = nums[endIdx] + min(doit(startIdx , endIdx-2 , nums) , doit(startIdx+1 , endIdx-1 , nums));
        return dp[startIdx][endIdx] = max(startSe , endSe);
    }
    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin() , nums.end() , 0);
        memset(dp , -1 , sizeof(dp));
        int player1Sum = doit(0 , nums.size()-1 , nums);
        cout << player1Sum;
        if(player1Sum >= (total - player1Sum)) return true;
        return false;
    }
};