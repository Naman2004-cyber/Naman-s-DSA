class Solution {
public:
    int dp[4][3][5001];
    int mod = 1e9+7;
    vector<pair<int , int>> dir = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int doit(int currx , int curry , vector<vector<char>> &matrix , int index , int n){
        if(index == n-1) return 1;
        if(dp[currx][curry][index] != -1) return dp[currx][curry][index];
        int ans = 0;
        for(int i = 0 ; i<dir.size() ; i++){
            int newx = currx + dir[i].first;
            int newy = curry + dir[i].second;
            if(newx >= 0 && newx <= 3 && newy >= 0  && newy <= 2 && matrix[newx][newy] != '*' && matrix[newx][newy] != '#'){
                ans = (ans + doit(newx , newy , matrix , index+1 , n))%mod;
            }
        }
        return dp[currx][curry][index] = ans;
    }
    int knightDialer(int n) {
        vector<vector<char>> matrix = {{'1' , '2' , '3'},
                                       {'4' , '5' , '6'},
                                       {'7' , '8' , '9'},
                                       {'*' , '0' , '#'}};
        memset(dp , -1 , sizeof(dp));
        int finalans = 0;
        for(int i = 0 ; i<4 ; i++){
            for(int j = 0 ; j<3 ; j++){
                if(matrix[i][j] != '*' && matrix[i][j] != '#'){
                    int use = doit(i , j , matrix , 0 , n);
                    finalans = (finalans + use)%mod;
                }   
            }
        }
        return finalans;
    }
};