class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> prefix(nums.size()+1);
        vector<int> suffix(nums.size()+1);
        int count0 = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            prefix[i] = count0;
            if(nums[i] == 0) count0++;
        }
        prefix[nums.size()] = count0;
        // for(int i = 0 ; i<prefix.size() ; i++) cout << prefix[i] << " ";
        int count1 = 0;
        for(int i = nums.size()-1 ; i>=0 ; i--)
        {
            if(nums[i] == 1) count1++;
            suffix[i] = count1;
        }
        suffix[nums.size()] = 0;
        // for(int i = 0 ; i<prefix.size() ; i++) cout << suffix[i] << " ";
        int maxi = 0;
        for(int i = 0 ; i<prefix.size() ; i++)
        {
            maxi = max(maxi , prefix[i]+suffix[i]);
        }
        vector<int> ans;
        for(int i = 0 ; i<prefix.size() ; i++)
        {
            if(suffix[i]+prefix[i] == maxi) ans.push_back(i);
        }
        return ans;
    }
};