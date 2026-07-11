class Solution {
public:
    void doit(int index , vector<int>& nums , int &ans , vector<bool> &visited , vector<int> &use){
        if(index == nums.size()){
            ans++;
            return;
        }
        for(int i = 0 ; i<nums.size() ; i++){
            if(visited[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
            if(!use.empty()){
                int num = nums[i] + use[use.size()-1];
                int root = sqrt(num);
                if(root*root != num) continue;
            }
            use.push_back(nums[i]);
            visited[i] = true;
            doit(index+1 , nums , ans , visited , use);
            use.pop_back();
            visited[i] = false;
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int ans = 0;
        vector<int> use;
        vector<bool> visited(nums.size() , false);
        doit(0 , nums , ans , visited , use);
        return ans;
    }
};