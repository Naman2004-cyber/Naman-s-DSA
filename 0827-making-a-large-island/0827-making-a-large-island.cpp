class Solution {
public:
    int r[4] = {0 , 1 , 0 , -1};
    int c[4] = {1 , 0 , -1 , 0};
    void doit(int currx , int curry , vector<vector<int>> &visited , vector<vector<int>>& grid , int &count , int parentx , int parenty , vector<vector<pair<int , pair<int , int>>>> &use){
        visited[currx][curry] = 1;
        use[currx][curry].second.first = parentx;
        use[currx][curry].second.second = parenty;
        count++;
        for(int k = 0 ; k<4 ; k++){
            int newx = currx + r[k];
            int newy = curry + c[k];
            if(newx >=0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && visited[newx][newy] == 0 && grid[newx][newy] == 1){
                doit(newx , newy , visited , grid , count , parentx , parenty , use);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m , vector<int>(n , 0));
        vector<vector<pair<int , pair<int , int>>>> use(m , vector<pair<int , pair<int , int>>>(n , {-1 , {-1 , -1}}));
        map<pair<int , int> , int> mpp;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    int count = 0;
                    doit(i , j , visited , grid , count , i , j , use);
                    // cout << count << endl;
                    mpp[{i , j}] = count;
                }
            }
        }
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(use[i][j].second.first != -1){
                    use[i][j].first = mpp[{use[i][j].second.first , use[i][j].second.second}];
                }
            }
        }
        int maxi = 0;
        int flag = 0;
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == 0){
                    flag = 1;
                    set<pair<int , pair<int , int>>> st;
                    for(int k = 0 ; k<4 ; k++){
                        int newx = i+r[k];
                        int newy = j+c[k];
                        if(newx >=0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && grid[newx][newy] == 1){
                            st.insert({use[newx][newy].first , {use[newx][newy].second.first , use[newx][newy].second.second}});
                        }
                    }
                    int sum = 0;
                    for(auto &it : st){
                        sum+=it.first;
                    }
                    maxi = max(maxi , sum+1);
                }
            }
        }
        if(flag == 0) return m*n;
        return maxi;
    }
};