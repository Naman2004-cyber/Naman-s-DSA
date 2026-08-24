class Solution {
public:
    long long mod = 1e9 + 7;
    long long dp1[100000];
    long long  dp2[100000];
    long long doit(int idx , vector<int>& nums1 , vector<int>& nums2 , int wr , unordered_map<int , int> &mpp1 , unordered_map<int , int>& mpp2){
        if((wr == 1 && idx == nums1.size()) || (wr == 2 && (idx == nums2.size()))) return 0;
        if(wr == 1 && dp1[idx] != -1) return dp1[idx];
        if(wr == 2 && dp2[idx] != -1) return dp2[idx];
        long long takeCurr = 0;
        long long shift = 0;
        if(wr == 1){
            takeCurr = nums1[idx] + doit(idx+1 , nums1 , nums2 , 1 , mpp1 , mpp2);
            if(mpp2.find(nums1[idx]) != mpp2.end()){
                shift = nums1[idx] + doit(mpp2[nums1[idx]]+1 , nums1 , nums2 , 2 , mpp1 , mpp2);
            }
        }
        else{
            takeCurr = nums2[idx] + doit(idx+1 , nums1 , nums2 , 2 , mpp1 , mpp2);
            if(mpp1.find(nums2[idx]) != mpp1.end()){
                shift = nums2[idx] + doit(mpp1[nums2[idx]]+1 , nums1 , nums2 , 1 , mpp1 , mpp2);
            }
        }
        long long maxi = max(takeCurr , shift);
        if(wr == 1) dp1[idx] = maxi;
        else dp2[idx] = maxi;
        return maxi;
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> mpp1 , mpp2;
        for(int i = 0 ; i<nums1.size() ; i++) mpp1[nums1[i]] = i;
        for(int i = 0 ; i<nums2.size() ; i++) mpp2[nums2[i]] = i;
        // 1 represents arr1 and 2 represents arr2
        memset(dp1 , -1 , sizeof(dp1));
        memset(dp2 , -1 , sizeof(dp2));
        long long  startNums1 = doit(0 , nums1 , nums2 , 1 , mpp1 , mpp2);
        long long startNums2 = doit(0 , nums1 , nums2 , 2 , mpp1 , mpp2);
        return max(startNums1 , startNums2)%mod;
    }
};