class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mpp(nums.size());
        vector<int> subarraySum(nums.size());
        int sum = 0;
        for(int i = n-1 ; i>=0 ; i--){
            sum+=nums[i];
            mpp[i] = sum;
            if(i+k-1 < n){
                int prefSum = sum;
                if(i+k < n) prefSum-=mpp[i+k];
                subarraySum[i] = prefSum;
            }
            else{
                subarraySum[i] = 0;
            }
        }
        int maxSumRight = 0;
        int maxIndexRight = -1;
        vector<int> maxIndexRightArray(nums.size());
        for(int i = n-1 ; i>=0 ; i--){
            if(subarraySum[i] >= maxSumRight){
                maxSumRight = subarraySum[i];
                maxIndexRight = i;
            }
            maxIndexRightArray[i] = maxIndexRight;
        }
        int maxSumLeft = 0;
        int maxIndexLeft = -1;
        vector<int> maxIndexLeftArray(nums.size());
        for(int i = 0 ; i<n ; i++){
            if(subarraySum[i] > maxSumLeft){
                maxSumLeft = subarraySum[i];
                maxIndexLeft = i;
            }
            maxIndexLeftArray[i] = maxIndexLeft;
        }
        vector<int> ans;
        int maxAns = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i == n-1 || i-k < 0 || i+k >= n) continue;
            int bestRight = maxIndexRightArray[i+k];
            int bestLeft = maxIndexLeftArray[i-k];
            if(subarraySum[i] > 0 && subarraySum[bestRight] > 0 && subarraySum[bestLeft] > 0){
                int sum = subarraySum[i] + subarraySum[bestRight] + subarraySum[bestLeft];
                if(sum > maxAns){
                    maxAns = sum;
                    ans = {bestLeft , i , bestRight};
                }
            }
            
        }
        return ans;
    }
};