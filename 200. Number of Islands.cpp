/*

题目描述：
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/


/*
解法1：BFS
time : O(N^2)
space : O(N^2)
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0, n, m;
        
        if(grid.size() == 0)return 0;
        
        n = grid.size(), m = grid[0].size();
        
        pair<int, int>p[n * m];
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j ++)
            {
                if(grid[i][j] == '1')
                {
                    res ++;
                    int tt = 0, hh = 0;
                    p[hh] = {i, j};
                    grid[i][j] = '0';

                    while(hh <= tt)
                    {
                        pair<int, int>tmp = p[hh ++];
                        int a = tmp.first, b = tmp.second;
                        for(int k = 0; k < 4; k++)
                        {
                            if(a + dx[k] < 0 || a + dx[k] >= n || b + dy[k] < 0 || b + dy[k] >= m || grid[a + dx[k]][b + dy[k]] == '0')continue;
                            p[++ tt] = {a + dx[k], b + dy[k]};
                            grid[a + dx[k]][b + dy[k]] = '0';
                        }

                    }
                }
            }
        }
        
        return res;
    }
};

/*
解法2：队列优化版BFS
time : O(N^2)
space : O(min(N, M))
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0, n, m;
        
        if(grid.size() == 0)return 0;
        
        n = grid.size(), m = grid[0].size();
        
        queue<pair<int, int>>p;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j ++)
            {
                if(grid[i][j] == '1')
                {
                    res ++;
                    p.push({i, j});
                    grid[i][j] = '0';

                    while(p.size())
                    {
                        pair<int, int>tmp = p.front();
                        p.pop();
                        int a = tmp.first, b = tmp.second;
                        for(int k = 0; k < 4; k++)
                        {
                            if(a + dx[k] < 0 || a + dx[k] >= n || b + dy[k] < 0 || b + dy[k] >= m || grid[a + dx[k]][b + dy[k]] == '0')continue;
                            p.push({a + dx[k], b + dy[k]});
                            grid[a + dx[k]][b + dy[k]] = '0';
                        }

                    }
                }
            }
        }
        
        return res;
    }
};

/*
解法3：
time : 
space : 
*/
