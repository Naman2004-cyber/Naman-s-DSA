class Solution {
public:
    int dp[100][201];
    int mod = 1e9 + 7;
    int doit(int curr , int end , int fuel , unordered_map<int , vector<int>> &adj , vector<int>& locations){
        // if(curr == end  && fuel == 0) return 1;
        if(dp[curr][fuel] != -1) return dp[curr][fuel];
        int count = 0;
        if(curr == end) count = 1;
        for(auto &it : adj[curr]){
            if(abs(locations[curr] - locations[it]) <= fuel){
                count = (count + doit(it , end , fuel-abs(locations[curr] - locations[it]) , adj , locations))%mod;
            }
        }
        return dp[curr][fuel] = count;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        unordered_map<int , vector<int>> adj;
        for(int i = 0 ; i<locations.size() ; i++){
            for(int j = 0 ; j<locations.size() ; j++){
                if(j != i && abs(locations[j]-locations[i]) <= fuel) adj[i].push_back(j);
            }
        }
        memset(dp , -1 , sizeof(dp));
        return doit(start , finish , fuel , adj , locations);
    }
};