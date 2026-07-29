class Solution {
public:
    int dp[500][500];
    int doit(int idx , vector<int>& satisfaction , int number){
        if(idx == satisfaction.size()) return 0;
        if(dp[idx][number] != -1) return dp[idx][number];
        int skip = doit(idx+1 , satisfaction , number);
        int take = satisfaction[idx]*number + doit(idx+1 , satisfaction , number+1);
        return dp[idx][number] = max(skip , take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin() , satisfaction.end());
        memset(dp , -1 , sizeof(dp));
        return doit(0 , satisfaction , 1);
    }
};