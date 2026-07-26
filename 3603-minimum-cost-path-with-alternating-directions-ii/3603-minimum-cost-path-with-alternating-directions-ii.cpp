class Solution {
public:
    int r[2] = {0 , 1};
    int c[4] = {1 , 0};
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<long long>>> cost(m,vector<vector<long long>>(n , vector<long long>(2 , LLONG_MAX)));
        priority_queue< pair<pair<long long,int> , pair<int , int>> , vector<pair<pair<long long,int> , pair<int , int>>> , greater<pair<pair<long long,int> , pair<int , int>>>> pq;
        pq.push({{1 , 1} , {0 , 0}});
        cost[0][0][1] = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long currCost = it.first.first;
            int currseconds = it.first.second;
            int currx = it.second.first;
            int curry = it.second.second;
            if(currCost > cost[currx][curry][currseconds]) continue;
            if(currx == m-1 && curry == n-1) return currCost;
            int newseconds = currseconds == 1 ? 0 : 1;
            if(currseconds == 1){
                for(int i = 0 ; i<2 ; i++){
                    int newx = currx + r[i];
                    int newy = curry + c[i];
                    long long newCost = 1LL * (newx+1)*(newy+1);
                    if(newx >=0 && newx < m && newy >=0 && newy < n && (currCost + newCost < cost[newx][newy][newseconds])){
                        cost[newx][newy][newseconds] = currCost + newCost;
                        pq.push({{cost[newx][newy][newseconds] , newseconds} , {newx , newy}});
                    }
                }
            }
            else{
                long long newCost = waitCost[currx][curry];
                if(currCost + newCost < cost[currx][curry][newseconds]){
                    cost[currx][curry][newseconds] = currCost + newCost;
                    pq.push({{cost[currx][curry][newseconds] , newseconds} , {currx , curry}});
                }
            }
        }
        return -1;
    }
};