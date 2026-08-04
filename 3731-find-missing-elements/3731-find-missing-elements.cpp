class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i<nums.size() ; i++){
           st.insert(nums[i]);
            maxi = max(maxi , nums[i]);
            mini = min(mini , nums[i]);
        }
        vector<int> ans;
        for(int i = mini ; i<= maxi ; i++){
            if(st.find(i) == st.end()) ans.push_back(i);
        }
        return ans;
    }
};