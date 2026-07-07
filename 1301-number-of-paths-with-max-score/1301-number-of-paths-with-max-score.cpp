class Solution {
public:
    int mod = 1000000000+7;
    int doit(int currx , int curry , vector<vector<int>> &matrix , vector<vector<int>> &dp , vector<vector<int>> &nomaxpath)
    {
        if(currx == 0 && curry == 0) 
        {
            nomaxpath[currx][curry] = 1;
            return 0;
        }
        if(dp[currx][curry] != INT_MIN) return dp[currx][curry];
        int left = -1;
        int up= -1;
        int upleft = -1;
        int m = matrix.size() , n = matrix[0].size();
        if(curry-1 >=0 && matrix[currx][curry-1] != 0) left = doit(currx , curry-1 , matrix , dp , nomaxpath);
        if(currx-1 >=0 && matrix[currx-1][curry] != 0) up = doit(currx-1 , curry , matrix , dp , nomaxpath);
        if(currx-1 >=0 && curry-1 >=0 && matrix[currx-1][curry-1] != 0) upleft = doit(currx-1 , curry-1 , matrix , dp , nomaxpath);
        int maxi = max(max(left , up) , upleft);
        if(maxi == -1){
            nomaxpath[currx][curry] = 0;
            return dp[currx][curry] =  -1;
        }
        int count = 0;
        if(left == maxi) count = (count+nomaxpath[currx][curry-1])%mod;
        if(up == maxi) count = (count+nomaxpath[currx-1][curry])%mod;
        if(upleft == maxi) count = (count+nomaxpath[currx-1][curry-1])%mod;
        nomaxpath[currx][curry] = count%mod;
        if(currx == m-1 && curry == n-1) return dp[currx][curry] = maxi;
        return dp[currx][curry] = matrix[currx][curry] + maxi;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size() , n = board[0].size();
        vector<vector<int>> matrix(m , vector<int>(n));
        int x = 0;
        for(int i = 0 ; i<board.size() ; i++){
            int y = 0;
            for(auto &it : board[i]){
                if(it == 'E' || it == 'S') matrix[x][y] = -1;
                else if(it == 'X') matrix[x][y] = 0;
                else matrix[x][y] = it - '0';
                y++;
            }
            x++;
        }
        vector<vector<int>> dp(m , vector<int>(n , INT_MIN));
        vector<vector<int>> nomaxpath(m , vector<int>(n , 0));
        int ans = doit(m-1 , n-1 , matrix , dp , nomaxpath);
        if(ans == -1) return {0,0};
        return {ans , nomaxpath[m-1][n-1]};
    }
};