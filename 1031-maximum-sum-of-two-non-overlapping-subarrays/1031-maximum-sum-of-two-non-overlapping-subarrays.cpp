class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> mpp(nums.size());
        int sum = 0;
        vector<int> sizeFirst(nums.size());
        vector<int> sizeSecond(nums.size());
        for(int i = 0 ; i<nums.size() ; i++){
            sum+=nums[i];
            if(i-firstLen+1 >= 0){
                int prevSum = 0;
                if(i-firstLen >= 0) prevSum = mpp[i-firstLen];
                int currSum = sum - prevSum;
                sizeFirst[i] = currSum;
            }
            else{
                sizeFirst[i] = 0;
            }

            if(i-secondLen+1 >= 0){
                int prevSum = 0;
                if(i-secondLen >= 0) prevSum = mpp[i-secondLen];
                int currSum = sum - prevSum;
                sizeSecond[i] = currSum;
            }
            else{
                sizeSecond[i] = 0;
            }
            mpp[i] = sum;
        }
        vector<int> maxFirst(nums.size());
        vector<int> maxSecond(nums.size());
        int firstmaxi = 0;
        int secondmaxi = 0;
        int ans = 0;
        for(int i = nums.size()-1 ; i>=0 ; i--){
            firstmaxi = max(firstmaxi , sizeFirst[i]);
            secondmaxi = max(secondmaxi , sizeSecond[i]);
            maxFirst[i] = firstmaxi;
            maxSecond[i] = secondmaxi;
            // pehle first
            int sum1 = sizeFirst[i];
            if(i+secondLen < nums.size()) sum1+=maxSecond[i+secondLen];
            ans = max(ans , sum1);
            // pehle second;
            int sum2 = sizeSecond[i];
            if(i+firstLen < nums.size()) sum2+=maxFirst[i+firstLen];
            ans = max(ans , sum2);
        }
        return ans;
    }
};