class Solution {
public:
    int dp[501][501];
    int mod = 1e9+7;
    int doit(int index , int currSteps , int arrLen , int steps){
        if(currSteps == steps){
            if(index == 0) return 1;
            return 0;
        }
        if(dp[index][currSteps] != -1) return dp[index][currSteps];
        int left = 0;
        int right = 0;
        int stay = 0;
        if(index-1 >= 0) left = left + doit(index-1 , currSteps+1 , arrLen , steps);
        if(index+1 < arrLen) right = right + doit(index+1 , currSteps+1 , arrLen , steps);
        stay = stay + doit(index , currSteps+1 , arrLen , steps);
        return dp[index][currSteps] = ((left+right)%mod+stay)%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(dp , -1 , sizeof(dp));
        return doit(0 , 0 , arrLen , steps);
    }
};