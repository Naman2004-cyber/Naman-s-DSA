class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() , 0);
        for(int i = 0 ; i<queries.size() ; i++){
            diff[queries[i][0]]--;
            if(queries[i][1]+1 < nums.size()) diff[queries[i][1] + 1]++;
        }
        for(int i = 1 ; i<nums.size() ; i++) diff[i]+=diff[i-1];

        for(int i = 0 ; i<nums.size() ; i++) 
        {
            if((nums[i] + diff[i]) > 0) return false;
        }
        return true;
    }
};