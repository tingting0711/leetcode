/*

题目描述：
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/


/*
解法1：暴力
time : O(N^3)
space : O(1)
Error: TLE
*/

class Solution {
public:
    /*
    *  Brute-Force O(N^3)
    */
    bool is_exist(int x, vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == x)return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            int current = 1;
            int tmp = nums[i];
            while(is_exist(tmp + 1, nums))
            {
                current ++;
                tmp ++;
            }
            res = max(res, current);
        }
        return res;
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
