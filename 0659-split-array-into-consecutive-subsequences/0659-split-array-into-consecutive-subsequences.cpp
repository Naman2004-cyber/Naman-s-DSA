class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int , int> freq;
        for(int i = 0 ; i<nums.size() ; i++) freq[nums[i]]++;
        unordered_map<int , int> need;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(freq[nums[i]] == 0) continue;
            if(need[nums[i]] > 0)
            {
                need[nums[i]]--;
                freq[nums[i]]--;
                need[nums[i]+1]++;
            }
            else
            {
                for(int j = 0 ; j<3 ; j++)
                {
                    if(freq[nums[i]+j] == 0) return false;
                    freq[nums[i]+j]--;
                }
                need[nums[i]+3]++;
            }
        }
        return true;
    }
};