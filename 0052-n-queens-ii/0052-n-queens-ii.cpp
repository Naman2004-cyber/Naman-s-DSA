

class Solution {
public:

    void solve(int col , vector<string> &board , vector<vector<string>> &ans , vector<int> &leftrow , vector<int> &upperdiagonal , vector<int> &lowerdiagonal , int n , int &count)
    {
        if(col == n)
            {
                ans.push_back(board);
                count++;
                return;
            }


        for(int row = 0 ; row < n ; row++)
        {
            if(leftrow[row] == 0 && upperdiagonal[n-1+col-row] == 0 && lowerdiagonal[row+col] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upperdiagonal[n-1+col-row] = 1;
                lowerdiagonal[row+col] = 1;
                solve(col+1,board,ans,leftrow,upperdiagonal,lowerdiagonal,n , count);
                board[row][col] = '.';
                leftrow[row] = 0;
                upperdiagonal[n-1+col-row] = 0;
                lowerdiagonal[row+col] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n , '.');
        for(int i = 0 ; i<n ; i++)
        {
            board[i] = s;
        }
        vector<vector<string>> ans;
        vector<int> leftrow(n,0);
        vector<int> upperdiagonal(2*n-1,0);
        vector<int> lowerdiagonal(2*n-1,0);
        int col = 0;
        int count = 0;
        solve(col,board,ans,leftrow,upperdiagonal,lowerdiagonal,n , count);

        return count;
    }
};