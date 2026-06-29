class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int x = -1;
        int y = -1;
        for(int i = 0 ; i<board.size() ; i++)
        {
            for(int j = 0 ; j<board[0].size() ; j++)
            {
                if(board[i][j] == 0)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        vector<vector<int>> correct = {{1,2,3},{4,5,0}};
        queue<pair<vector<vector<int>> , pair<int , int>>> qt;
        qt.push({board , {x , y}});
        set<vector<vector<int>>> st;
        st.insert(board);
        int r[4] = {0,1,0,-1};
        int c[4] = {1,0,-1,0};
        int moves = 0;
        while(!qt.empty())
        {
            int n = qt.size();
            for(int i = 0 ; i<n ; i++)
            {
                auto it = qt.front();
                qt.pop();
                vector<vector<int>> matrix = it.first;
                int currx = it.second.first;
                int curry = it.second.second;
                if(matrix == correct) return moves;
                for(int j = 0 ; j<4 ; j++)
                {
                    vector<vector<int>> store = matrix;
                    int newx = currx + r[j];
                    int newy = curry + c[j];
                    if(newx >=0 && newx < board.size() && newy >=0 && newy < board[0].size())
                    {
                        swap(matrix[currx][curry] , matrix[newx][newy]);
                        if(st.find(matrix) == st.end()) 
                        {
                            qt.push({matrix , {newx , newy}});
                            st.insert(matrix);
                        }
                        matrix = store;
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};