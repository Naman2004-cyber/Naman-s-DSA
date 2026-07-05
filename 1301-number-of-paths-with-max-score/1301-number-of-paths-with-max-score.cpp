class Solution {
public:
    int mod = 1000000000 + 7;
    int doit(int currx , int curry , vector<vector<int>> &matrix , vector<vector<int>> &dp , vector<vector<int>> &nomaxpath)
    {
        if(currx == 0 && curry == 0) 
        {
            nomaxpath[0][0] = 1;
            return 0;
        }
        if(dp[currx][curry] != -1) return dp[currx][curry];
        int left = INT_MIN;
        int up= INT_MIN;
        int upleft = INT_MIN;
        if(curry-1 >=0 && matrix[currx][curry-1] != 0)
        {
            left = doit(currx , curry-1 , matrix , dp , nomaxpath);
        }
        if(currx-1 >=0 && matrix[currx-1][curry] != 0)
        {
            up = doit(currx-1 , curry , matrix , dp , nomaxpath);
        }
        if(currx-1 >=0 && curry-1>=0 && matrix[currx-1][curry-1] != 0)
        {
            upleft = doit(currx-1 , curry-1 , matrix , dp , nomaxpath);
        }
        int maxi = max(left , max(up , upleft));
        if(maxi == INT_MIN)
        {
            nomaxpath[currx][curry] = 0;
            return dp[currx][curry] = INT_MIN;
        }
        int count = 0;
        if(left != INT_MIN && left == maxi && curry-1 >=0 && matrix[currx][curry-1] != 0) count = (count + nomaxpath[currx][curry-1])%mod;
        if(up != INT_MIN && up == maxi && currx-1 >=0 && matrix[currx-1][curry] != 0) count = (count + nomaxpath[currx-1][curry])%mod;
        if(upleft != INT_MIN && upleft == maxi && curry-1 >=0 && currx-1 >=0 && matrix[currx-1][curry-1] != 0) count = (count + nomaxpath[currx-1][curry-1])%mod;
        nomaxpath[currx][curry] = count;
        if(matrix[currx][curry] == -1) return dp[currx][curry] = max(left , max(up , upleft));
        return dp[currx][curry] = matrix[currx][curry] + max(left , max(up , upleft));
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> matrix(m , vector<int>(n));
        int i = 0;
        for(auto &it : board)
        {
            int j = 0;
            for(auto &a : it)
            {
                if(a == 'E' || a == 'S')
                {
                    matrix[i][j] = -1;
                }
                else if(a == 'X')
                {
                    matrix[i][j] = 0;
                }
                else
                {
                    matrix[i][j] = a-'0';
                }
                j++;
            }
            i++;
        }
        vector<vector<int>> dp(m , vector<int>(n , -1));
        vector<vector<int>> nomaxpath(m , vector<int>(n , 0));
        int ans = doit(m-1 , n-1 , matrix , dp , nomaxpath);
        if(ans == INT_MIN) return {0,0};
        return {ans , nomaxpath[m-1][n-1]};
    }
};