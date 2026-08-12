class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxQue , minQue;
        int l = 0 , r = 0 , maxi = 0;
        while(r < nums.size()){
            while(!maxQue.empty() && maxQue.back() < nums[r]) maxQue.pop_back();
            maxQue.push_back(nums[r]);
            while(!minQue.empty() && minQue.back() > nums[r]) minQue.pop_back();
            minQue.push_back(nums[r]);
            while(maxQue.front()-minQue.front() > limit){
                if(maxQue.front() == nums[l]) maxQue.pop_front();
                if(minQue.front() == nums[l]) minQue.pop_front();
                l++;
            }
            maxi = max(maxi , r-l+1);
            r++;
        }
        return maxi;
    }
};