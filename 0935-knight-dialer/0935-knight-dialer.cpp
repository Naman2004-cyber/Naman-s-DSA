class Solution {
public:
    int prev[4][3];
    int curr[4][3];
    int mod = 1e9+7;
    vector<pair<int , int>> dir = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    int knightDialer(int n) {
        vector<vector<char>> matrix = {{'1' , '2' , '3'},
                                       {'4' , '5' , '6'},
                                       {'7' , '8' , '9'},
                                       {'*' , '0' , '#'}};
        for(int i = 0 ; i<4 ; i++){
            for(int j = 0 ; j<3 ; j++){
                if(matrix[i][j] != '*' && matrix[i][j] != '#') prev[i][j] = 1;
            }
        }
        for(int index =  n-1; index>=1 ; index--){
            for(int i = 0 ; i<4 ; i++){
                for(int j = 0 ; j<3 ; j++){
                    if(matrix[i][j] == '*' || matrix[i][j] == '#') continue;
                    int ans = 0;
                    for(int k = 0 ; k<dir.size() ; k++){
                        int newx = dir[k].first + i;
                        int newy = dir[k].second + j;
                        if(newx >=0 && newx <= 3 && newy >=0 && newy <= 2 && matrix[newx][newy] != '*' && matrix[newx][newy] != '#'){
                            ans = (ans + prev[newx][newy])%mod;
                        }
                    }
                    curr[i][j] = ans;
                }
            }
            swap(curr , prev);
        }
        int finalans = 0;
        for(int i = 0 ; i<4 ; i++){
            for(int j = 0 ; j<3 ; j++){
                if(matrix[i][j] != '*' && matrix[i][j] != '#'){
                    finalans = (finalans + prev[i][j])%mod;
                }   
            }
        }
        return finalans;
    }
};