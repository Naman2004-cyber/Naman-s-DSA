class Solution {
public:
    void doit(int index , vector<int>& nums , vector<vector<int>> &ans , vector<int> &use , vector<bool> &visited){
        if(index == nums.size()){
            ans.push_back(use);
            return;
        }
        for(int i = 0 ; i<nums.size() ; i++){
            if(visited[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
            use.push_back(nums[i]);
            visited[i] = true;
            doit(index+1 , nums , ans , use , visited);
            use.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> use;
        vector<bool> visited(nums.size() , false);
        doit(0 , nums , ans , use , visited);
        return ans;
    }
};