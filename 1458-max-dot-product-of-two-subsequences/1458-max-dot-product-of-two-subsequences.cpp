class Solution {
public:
    int dp[500][500];
    int doit(int idx1 , int idx2 , vector<int>& nums1 , vector<int>& nums2){
        if(idx1 == nums1.size() || idx2 == nums2.size()){
            return INT_MIN;
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        // int skipBoth = doit(idx1+1 , idx2+1 , nums1 , nums2 , started);
        int skip1 = doit(idx1+1 , idx2 , nums1 , nums2);
        int skip2 = doit(idx1 , idx2+1 , nums1 , nums2);
        int take = nums1[idx1]*nums2[idx2] + max(0 , doit(idx1+1 , idx2+1 , nums1 , nums2));
        return dp[idx1][idx2] = max(max(skip1 , skip2) , take);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , nums1 , nums2);
    }
};