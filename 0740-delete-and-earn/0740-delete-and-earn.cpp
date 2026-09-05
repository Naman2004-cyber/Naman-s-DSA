class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin() , nums.end());
        vector<int> freq(maxi+1 , 0);
        for(int i = 0 ; i<nums.size() ; i++) freq[nums[i]]++;
        int nextNext = 0; // maxi + 1
        int next = maxi*freq[maxi]; // maxi
        for(int i = maxi-1 ; i>=1 ; i--){
            int skip = next;
            int take = 0;
            if(freq[i] > 0) take = i*freq[i] + nextNext;
            int curr = max(skip , take);
            nextNext = next;
            next = curr;
        }
        return next;
    }
};