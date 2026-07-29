class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int l = 0;
        int r = 0;
        int consecutive = 1;
        while(r < nums.size()){
            if(r > 0  && (nums[r]-nums[r-1] == 1)){
                consecutive++;
            }
            else{
                consecutive = 1;
            }
            if(r-l+1 == k){
                if(consecutive >= k){
                    ans.push_back(nums[r]);
                }
                else{
                    ans.push_back(-1);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};