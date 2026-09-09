class Solution {
public:
    int mod = 1e9+7;
    int countHousePlacements(int n) {
        int NN = 0 , N = 1;
        for(int i = n-2 ; i>=0 ; i--){
            int skip = N , take = 1 + NN;
            int curr = (take + skip)%mod;
            NN = N;
            N = curr;
        }
        int ans = 1 + N;
        int finalAns = (1LL * ans * ans)%mod;
        return finalAns;
    }
};