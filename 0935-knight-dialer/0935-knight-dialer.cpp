class Solution {
public:
    int dp[4][3][5001];
    int mod = 1e9+7;
    vector<pair<int , int>> dir = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int knightDialer(int n) {
        vector<vector<char>> matrix = {{'1' , '2' , '3'},
                                       {'4' , '5' , '6'},
                                       {'7' , '8' , '9'},
                                       {'*' , '0' , '#'}};
        for(int i = 0 ; i<4 ; i++){
            for(int j = 0 ; j<3 ; j++){
                if(matrix[i][j] != '*' && matrix[i][j] != '#') dp[i][j][n] = 1;
            }
        }
        for(int index =  n-1; index>=0 ; index--){
            for(int i = 0 ; i<4 ; i++){
                for(int j = 0 ; j<3 ; j++){
                    if(matrix[i][j] == '*' || matrix[i][j] == '#') continue;
                    int ans = 0;
                    for(int k = 0 ; k<dir.size() ; k++){
                        int newx = dir[k].first + i;
                        int newy = dir[k].second + j;
                        if(newx >=0 && newx <= 3 && newy >=0 && newy <= 2 && matrix[newx][newy] != '*' && matrix[newx][newy] != '#'){
                            ans = (ans + dp[newx][newy][index+1])%mod;
                        }
                    }
                    dp[i][j][index] = ans;
                }
            }
        }
        int finalans = 0;
        for(int i = 0 ; i<4 ; i++){
            for(int j = 0 ; j<3 ; j++){
                if(matrix[i][j] != '*' && matrix[i][j] != '#'){
                    finalans = (finalans + dp[i][j][1])%mod;
                }   
            }
        }
        return finalans;
    }
};