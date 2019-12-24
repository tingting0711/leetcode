/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

*/


/*
解法1：BFS
time : 线性
space : 
*/

class Solution {
public:
    int numSquares(int n) {
        unordered_map<int, int>existed;
        queue<pair<int, int>>q;
        for(int i = 1; i * i <= n; i++)
        {
            if(i * i == n)return 1;
            q.push({i * i, 1});
            existed.insert({i * i, 1});
        }
        while(q.size())
        {
            pair<int, int>tmp = q.front(); q.pop();
            for(int i = 1; tmp.first + i * i <= n; i++)
            {
                int t = i * i + tmp.first;
                if(t == n)return tmp.second + 1;
                
                if(t < n && existed.count(t) == 0)
                {
                    q.push({t, tmp.second + 1});
                    existed.insert({t, tmp.second + 1});
                }
            }
        }
        return 0;
    }
};

/*
解法2：DP
time : O(N^2)
space : 
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++)
        {
            dp[i] = i;
            for(int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        return dp[n];
    }
};

/*
解法3：
time : 
space : 
*/
