/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


*/

//二维表示

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int f[n][n]; // vector<vector<long long>> f(n, vector<long long>(n));
        f[0][0] = triangle[0][0];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                f[i][j] = INT_MAX;
                if(j < i)f[i][j] = f[i - 1][j];
                if(j - 1 >= 0)f[i][j] = min(f[i][j], f[i - 1][ j - 1]);
                f[i][j] += triangle[i][j];
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < n; i++)res = min(res, f[n - 1][i]);
        return res;
    }
};

// 滚动数组
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int f[2][n]; // vector<vector<long long>> f(n, vector<long long>(n));
        f[0][0] = triangle[0][0];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                f[i & 1][j] = INT_MAX;
                if(j < i)f[i & 1][j] = f[i - 1 & 1][j];
                if(j - 1 >= 0)f[i & 1][j] = min(f[i & 1][j], f[i - 1 & ][ j - 1]);
                f[i & 1][j] += triangle[i][j];
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < n; i++)res = min(res, f[n - 1 & 1][i]);
        return res;
    }
};

//一维表示

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int f[n];
        f[0] = triangle[0][0];
        for(int i = 1; i < n; i++)
        {
            for(int j = i; j >= 0; j--)
            {
                if(j >= i)f[j] = INT_MAX;
                if(j - 1 >= 0)f[j] = min(f[j], f[ j - 1]);
                f[j] += triangle[i][j];
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < n; i++)res = min(res, f[i]);
        return res;
    }
};

/*
time : O(N);
space : O(N) 
*/