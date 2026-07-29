class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        unordered_map<int , int> mpp;
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
        // for(int i = 0 ; i<nums.size() ; i++) cout << sizeFirst[i] << " ";
        // cout << endl;
        // for(int i = 0 ; i<nums.size() ; i++) cout << sizeSecond[i] << " ";
        int maxi = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            int startSecond = i+secondLen;
            for(int j = startSecond ; j<nums.size() ; j++){
                maxi = max(maxi , sizeFirst[i]+sizeSecond[j]);
            }

            int startFirst = i+firstLen;
            for(int j = startFirst ; j<nums.size() ; j++){
                maxi = max(maxi , sizeSecond[i]+sizeFirst[j]);
            }
        }
        return maxi;
    }
};