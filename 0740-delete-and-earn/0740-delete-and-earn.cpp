class Solution {
public:
    // int doit(int num , vector<int>& freq , vector<int>&dp){
    //     if(num >= freq.size()) return 0;
    //     if(dp[num] != -1) return dp[num];
    //     int skip = doit(num+1 , freq , dp);
    //     int take = 0;
    //     if(freq[num] > 0) take = num * freq[num] + doit(num+2 , freq , dp);
    //     return dp[num] = max(take , skip);
    // }
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin() , nums.end());
        vector<int> freq(maxi+1 , 0);
        vector<int> dp(maxi+2 , -1);
        for(int i = 0 ; i<nums.size() ; i++) freq[nums[i]]++;
        dp[maxi+1] = 0;
        dp[maxi] = maxi*freq[maxi];
        for(int i = maxi-1 ; i>=1 ; i--){
            int skip = dp[i+1];
            int take = 0;
            if(freq[i] > 0) take = i*freq[i] + dp[i+2];
            dp[i] = max(skip , take);
        }
        return dp[1];
    }
};