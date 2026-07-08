class Solution {
public:
    int doit(int index , vector<int> &use , unordered_map<int , int> &mpp , vector<int> &dp)
    {
        if(index >= use.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int skip = doit(index+1 , use , mpp , dp);
        int take = 0;
        if(index+1 < use.size() && use[index+1] == use[index]+1){
            take = use[index]*mpp[use[index]] + doit(index+2 , use , mpp , dp);
        }
        else{
            take = use[index]*mpp[use[index]] + doit(index+1 , use , mpp , dp);
        }
        return dp[index] = max(take , skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int> use;
        unordered_map<int , int> mpp;
        for(int i = 0 ; i<nums.size() ; i++){
            if(mpp.find(nums[i]) == mpp.end()) use.push_back(nums[i]);
            mpp[nums[i]]++;
        }
        sort(use.begin() , use.end());
        vector<int> dp(use.size() , -1);
        return doit(0 , use , mpp , dp);
    }
};