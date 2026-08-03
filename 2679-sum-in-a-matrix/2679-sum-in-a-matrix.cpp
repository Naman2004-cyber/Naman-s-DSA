class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int count = 0;
        for(int i = 0 ; i<m ; i++) sort(nums[i].begin() , nums[i].end());
        for(int j = 0 ; j<n ; j++){
            int maxi = 0;
            for(int i = 0 ; i<m ; i++){
                maxi = max(maxi , nums[i][j]);
            }
            count+=maxi;
        }
        return count;
    }
};