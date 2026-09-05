class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long nn = 0 ,  n = nums[nums.size()-1];
        for(int i = nums.size()-2 ; i>=0 ; i--){
            long long skip = n , take = nums[i];
            if(colors[i] != colors[i+1]) take+=n;
            else take+=nn;
            long long curr = max(take , skip);
            nn = n;
            n = curr;
        }
        return n;
    }
};