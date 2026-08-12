class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> minEffort(m , vector<int>(n , INT_MAX));
        priority_queue<pair< int , pair<int , int>> , vector<pair< int , pair<int , int>>> , greater<pair< int , pair<int , int>>>> pq;
        pq.push({0 , {0 , 0}});
        minEffort[0][0] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int currEffort = it.first;
            int currx = it.second.first;
            int curry = it.second.second;
            if(currEffort > minEffort[currx][curry]) continue;
            if(currx == m-1 && curry == n-1) return currEffort;
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx >=0  && newx < m && newy >= 0  && newy < n){
                    int newEffort = max(currEffort , abs(heights[currx][curry] - heights[newx][newy]));
                    if(newEffort < minEffort[newx][newy]){
                        minEffort[newx][newy] = newEffort;
                        pq.push({newEffort , {newx , newy}});
                    }
                }
            }
        }
        return 0;
    }
};