class Solution {
public:
    int prev[3][3];
    int curr[3][3];
    int mod = 1e9+7;
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i<=2 ; i++){
            for(int j = 0 ; j<=2 ; j++){
                prev[i][j] = 1;
            }
        }
        for(int idx = n-1 ; idx>=0 ; idx--){
            for(int count_even = 0 ; count_even <=2 ; count_even++){
                for(int count_odd = 0 ; count_odd <= 2 ; count_odd++){
                    int take = 0;
                    int skip = 0;
                    skip = skip + prev[count_even][count_odd];
                    if(nums[idx]%2 == 0 && count_even <= 1){
                        take = (take + prev[count_even+1][0])%mod;
                    }
                    if(nums[idx]%2 != 0 && count_odd <= 1){
                        take = (take + prev[0][count_odd+1])%mod;
                    }
                    curr[count_even][count_odd] = (take+skip)%mod;
                }
            }
            swap(prev , curr);
        }
        return prev[0][0]-1;
    }
};