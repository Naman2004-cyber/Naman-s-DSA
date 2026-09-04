class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1} , c[4] = {1 , 0 , -1 , 0};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<tuple<int , int , int> , vector<tuple<int , int , int>> , greater<tuple<int , int , int>>> pq;
        vector<vector<int>> minMaxValue(m , vector<int>(n , INT_MAX));
        pq.push({grid[0][0] , 0 , 0});
        minMaxValue[0][0] = grid[0][0];
        while(!pq.empty()){
            auto [currMax , currx , curry] = pq.top();
            pq.pop();
            if(currMax > minMaxValue[currx][curry]) continue;
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx < 0 || newy < 0 || newx >= m || newy >= n) continue;
                int newMax = max(currMax , grid[newx][newy]);
                if(newMax < minMaxValue[newx][newy]){
                    minMaxValue[newx][newy] = newMax;
                    pq.push({newMax , newx , newy});
                }
            }
        }
        vector<int> pref(1e6+1 , 0);
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                pref[minMaxValue[i][j]]++;
            }
        }
        for(int i = 1 ; i<pref.size() ; i++){
            pref[i]+=pref[i-1];
        }

        // for(int i = 1 ; i<10 ; i++) cout << pref[i] << " ";

        vector<int> ans(queries.size());
        for(int i = 0 ; i<queries.size() ; i++){
            ans[i] = pref[queries[i]-1];
        }
        
        return ans;
    }
};