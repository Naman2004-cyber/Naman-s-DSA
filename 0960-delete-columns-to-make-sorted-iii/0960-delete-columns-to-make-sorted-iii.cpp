class Solution {
public:
    int dp[101][101];
    int doit(int idx , int prevIdx , vector<string>& strs , int n){
        if(idx > n) return 0;
        if(dp[idx][prevIdx] != -1) return dp[idx][prevIdx];
        int notTake = doit(idx+1 , prevIdx , strs , n);
        int take = INT_MIN;
        if(prevIdx == 0){
            take = 1 + doit(idx+1 , idx , strs , n);
        }
        else{
            int flag = 0;
            for(int i = 0 ; i<strs.size() ; i++){
                if(strs[i][prevIdx-1] > strs[i][idx-1]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                take = 1 + doit(idx+1 , idx , strs , n);
            }
        }
        return dp[idx][prevIdx] = max(notTake , take);
    }
    int minDeletionSize(vector<string>& strs) {
        int prevIdx = 0;
        memset(dp , -1 , sizeof(dp));
        int longest = doit(1 , prevIdx , strs , strs[0].size());
        return strs[0].size() - longest;
    }
};