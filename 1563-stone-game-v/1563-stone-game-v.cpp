class Solution {
public:
    int dp[500][500];
    int doit(int l , int r , vector<int> &preSum){
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int maxi = INT_MIN;
        for(int j = l ; j<r ; j++){
            // first half is l to j and second half is j+1 to r
            int remove = l-1 >=0 ? preSum[l-1] : 0;
            int leftSum = preSum[j] - remove;
            int rightSum = preSum[r] - preSum[j];
            int ans = 0;
            // cout << leftSum << " " << rightSum << endl;
            if(leftSum == rightSum){
                ans = leftSum + max(doit(l , j , preSum) , doit(j+1 , r , preSum));
            }
            else if(leftSum > rightSum){
                ans = rightSum + doit(j+1 , r , preSum);
            }
            else{
                ans = leftSum + doit(l , j , preSum);
            }
            maxi = max(maxi , ans);
        }
        return dp[l][r] = maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> preSum(n);
        int sum = 0;
        for(int i = 0 ; i<n ; i++){
            sum+=stoneValue[i];
            preSum[i] = sum;
        }
        memset(dp , -1 , sizeof(dp));
        return doit(0 , n-1 , preSum);
    }
};