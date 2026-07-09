class Solution {
public:
    int doit(int index , int prevSwap , vector<int>& nums1, vector<int>& nums2 , vector<vector<int>> &dp)
    {
        if(index == nums1.size()) return 0;
        if(dp[index][prevSwap] != -1) return dp[index][prevSwap];
        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];
        if(prevSwap) swap(prev1 , prev2);
        int ans = 1e9;
        // dont swap
        if(prev1 < nums1[index] && prev2 < nums2[index]){
            ans = min(ans , doit(index+1 , 0 , nums1 , nums2 , dp));
        }
        // swap if condition
        if(prev1 < nums2[index] && prev2 < nums1[index]){
            ans = min(ans , 1 + doit(index+1 , 1 , nums1 , nums2 , dp));
        }
        return dp[index][prevSwap] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int ans = 1e9;
        vector<vector<int>> dp(nums1.size() , vector<int>(2 , -1));
        // dont swap 0
        ans = min(ans , doit(1 , 0 , nums1 , nums2 , dp));
        // swap 0
        ans = min(ans , 1 + doit(1 , 1 , nums1 , nums2 , dp));
        return ans;
    }
};