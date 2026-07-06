class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<nums.size() ; i++) mpp[nums[i]]++;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(mpp[nums[i]] == 0) continue;
            for(int j = 0 ; j<k ; j++)
            {
                if(mpp[nums[i]+j] == 0) return false;
                mpp[nums[i]+j]--;
            }
        }
        return true;
    }
};