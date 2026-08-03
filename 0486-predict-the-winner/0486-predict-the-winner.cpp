class Solution {
public:
    int dp[20][20];
    int doit(int startIdx , int endIdx , vector<int>& nums){
        if(startIdx > endIdx) return 0;
        if(dp[startIdx][endIdx] != -1) return dp[startIdx][endIdx];
        int startSe = nums[startIdx] - doit(startIdx+1 , endIdx , nums);
        int endSe = nums[endIdx] - doit(startIdx , endIdx-1 , nums);
        return dp[startIdx][endIdx] = max(startSe , endSe);
    }
    bool predictTheWinner(vector<int>& nums) {
        int total = accumulate(nums.begin() , nums.end() , 0);
        memset(dp , -1 , sizeof(dp));
        int ans = doit(0 , nums.size()-1 , nums);
        if(ans >= 0) return true;
        return false;
    }
};