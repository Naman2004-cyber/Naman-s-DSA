class Solution {
public:
    long long dp[100001];
    // static bool cmp(const vector<int>& a , const vector<int>& b){
    //     return a[0] < b[0];
    // }
    long long doit(int idx , vector<vector<int>>& rides){
        if(idx == rides.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long notPick = doit(idx+1 , rides);
        long long pick = 0;
        // apply binary search to know the next nonoverlapping ride 
        int index = rides.size();
        int start = idx+1;
        int end = rides.size()-1;
        while(start <= end){
            int mid = start + ((end-start)/2);
            if(rides[mid][0] >= rides[idx][1]){
                index = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        pick = rides[idx][1] - rides[idx][0] + rides[idx][2] + doit(index , rides);
        return dp[idx] = max(notPick , pick);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin() , rides.end());
        memset(dp , -1 , sizeof(dp));
        return doit(0 , rides);
    }
};