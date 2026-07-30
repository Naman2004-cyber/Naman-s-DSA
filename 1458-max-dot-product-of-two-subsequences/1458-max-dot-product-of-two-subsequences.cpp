class Solution {
public:
    int dp[500][500][2];
    int doit(int idx1 , int idx2 , vector<int>& nums1 , vector<int>& nums2 , int started){
        if(idx1 == nums1.size() || idx2 == nums2.size()){
            if(started) return 0;
            return INT_MIN;
        }
        if(dp[idx1][idx2][started] != -1) return dp[idx1][idx2][started];
        int skipBoth = doit(idx1+1 , idx2+1 , nums1 , nums2 , started);
        int skip1 = doit(idx1+1 , idx2 , nums1 , nums2 , started);
        int skip2 = doit(idx1 , idx2+1 , nums1 , nums2 , started);
        int take = nums1[idx1]*nums2[idx2] + doit(idx1+1 , idx2+1 , nums1 , nums2 , 1);
        return dp[idx1][idx2][started] = max(max(skipBoth , skip1) , max(skip2 , take));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , nums1 , nums2 , 0);
    }
};