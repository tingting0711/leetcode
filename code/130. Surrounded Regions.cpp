/*

题目描述：
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/


/*
解法1：BFS
time : O(N^2)
space : O(N^2)
*/

class Solution {
public:
    int n, m;
    vector<vector <bool>>is_board;
    void bfs(int x, int y, vector<vector<char>>& board)
    {
        is_board[x][y] = true;
        int hh = 0, tt = -1;
        pair<int, int> q[n * m];
        q[++ tt] = {x, y};
        
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        
        while(hh <= tt)
        {
            pair<int, int> tmp = q[hh ++];
            int a = tmp.first, b = tmp.second;
            
            for(int i = 0; i < 4; i ++)
            {
                if(a + dx[i] < 0 || a + dx[i] >= n || b + dy[i] < 0 || b + dy[i] >= m || board[a + dx[i]][b + dy[i]] != 'O' || is_board[a + dx[i]][b + dy[i]])continue;
                q[++ tt] = {a + dx[i], b + dy[i]};
                is_board[a + dx[i]][b + dy[i]] = true;
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)return;
        n = board.size(), m = board[0].size();
        vector<bool>tmp;
        for(int i = 0; i < m; i++)tmp.push_back(false);
        for(int j = 0; j < n; j++)is_board.push_back(tmp);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O' && !is_board[i][j])
                {
                    bfs(i, j, board);
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O' && !is_board[i][j])board[i][j] = 'X';
            }
        }
        return;
    }
};


/*
解法2：
time : 
space : 
*/



/*
解法3：
time : 
space : 
*/
