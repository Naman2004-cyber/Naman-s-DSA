class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<long long>>> cost(m , vector<vector<long long>>(n , vector<long long>(2 , LLONG_MAX)));
        priority_queue<pair<pair<long long , int> , pair<int , int>> , vector<pair<pair<long long , int> , pair<int , int>>> , greater<pair<pair<long long , int> , pair<int , int>>>> pq;
        cost[0][0][1] = 1;
        pq.push({{1 , 1},{0 , 0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long currCost = it.first.first;
            int currParity = it.first.second;
            int currx = it.second.first;
            int curry = it.second.second;
            if(currCost > cost[currx][curry][currParity]) continue;
            if(currx == m-1 && curry == n-1) return currCost;
            int newParity = currParity == 1 ? 0 : 1;
            for(int i = 0 ; i<4 ; i++){
                int newx = currx + r[i];
                int newy = curry + c[i];
                if(newx >=0 && newx < m && newy >=0 && newy < n){
                    long long newCost = 1LL * (newx+1) * (newy+1);
                    if(   (   (currParity == 1)    && (i == 2 || i == 3)   )   || (   (currParity == 0)    && (i == 0 || i == 1)   ) ){
                        newCost+=penalty[currx][curry];
                    }

                    if(currCost + newCost < cost[newx][newy][newParity]){
                        cost[newx][newy][newParity] = currCost + newCost;
                        pq.push({{cost[newx][newy][newParity],newParity},{newx , newy}});
                    }
                }
            }
            if(currCost + penalty[currx][curry] < cost[currx][curry][newParity]){
                cost[currx][curry][newParity] = currCost + penalty[currx][curry];
                pq.push({{cost[currx][curry][newParity],newParity},{currx , curry}});
            }
        }
        return -1;
    }
};