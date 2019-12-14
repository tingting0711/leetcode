/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right


*/
//二维数组
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<long long>>f(n, vector<long long>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(nums[i][j])f[i][j] = 0;
                else if(!i && !j)f[i][j] = 1;
                else if(!i)f[i][j] = f[i][ j - 1];
                else if(!j)f[i][j] = f[i - 1][j];
                else f[i][j] = f[i - 1][j] + f[i][j - 1];
            }
        }
        return f[n - 1][m - 1];
    }
};

//滚动数组
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<long long>>f(2, vector<long long>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(nums[i][j])f[i & 1][j] = 0;
                else if(!i && !j)f[i & 1][j] = 1;
                else if(!i)f[i & 1][j] = f[i & 1][ j - 1];
                else if(!j)f[i & 1][j] = f[i - 1 & 1][j];
                else f[i & 1][j] = f[i - 1 & 1][j] + f[i & 1][j - 1];
            }
        }
        return f[n - 1 & 1][m - 1];
    }
};


/*
time :  O(N)
space : O(N)
*/