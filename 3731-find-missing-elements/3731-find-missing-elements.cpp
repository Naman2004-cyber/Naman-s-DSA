class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int , int> mpp;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i<nums.size() ; i++){
            mpp[nums[i]]++;
            maxi = max(maxi , nums[i]);
            mini = min(mini , nums[i]);
        }
        vector<int> ans;
        for(int i = mini ; i<= maxi ; i++){
            if(mpp.find(i) == mpp.end()) ans.push_back(i);
        }
        return ans;
    }
};