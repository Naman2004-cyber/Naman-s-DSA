class Solution {
public:
    int dp[10001];
    int doit(int num , vector<int>& freq){
        if(num >= freq.size()) return 0;
        if(dp[num] != -1) return dp[num];
        int skip = doit(num+1 , freq);
        int take = 0;
        if(freq[num] > 0){
            take = num * freq[num] + doit(num+2 , freq);
        }
        return dp[num] = max(take , skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> freq(10001 , 0);
        memset(dp , -1 , sizeof(dp));
        for(int i = 0 ; i<nums.size() ; i++) freq[nums[i]]++;
        return doit(1 , freq);
    }
};