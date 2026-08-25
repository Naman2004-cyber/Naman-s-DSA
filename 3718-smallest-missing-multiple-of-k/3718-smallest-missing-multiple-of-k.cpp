class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> freq(10001 , 0);
        for(int i = 0 ; i<nums.size() ; i++) freq[nums[i]]++;
        for(int i = k ; i<=10001 ; i+=k){
            if(freq[i] == 0) return i;
        }
        return 0;
    }
};