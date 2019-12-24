/*

题目描述：

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

*/


/*
1612ms
解法1：朴素BFS搜索
time : O(N)线性时间
space : O(N^2)
note : 注意要先初始化check[][]以免多余查询操作

*/

class Solution {
public:
    bool change(string a, string b)
    {
        int cnt = 0;
        for(int i = 0; i < a.size(); i++)
            if(a[i] != b[i])cnt ++;
        if(cnt == 1)return true;
        return false;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size() + 1;
        int dist[n];
        bool check[n][n];
        memset(check, false, sizeof check);
        memset(dist, 0, sizeof dist);
        dist[wordList.size() - 1] = 1;
        int end;
        for(int i = 0; i < wordList.size(); i++)
        {
            if(wordList[i] == endWord)end = i;
            for(int j = i; j < wordList.size(); j++)
            {
                if(change(wordList[i], wordList[j]))
                {
                    check[i][j] = check[j][i] = true;
                }
            }
        }
        queue<int>q;
        q.push(wordList.size() - 1);
        while(q.size())
        {
            int tmp = q.front();
            q.pop();
            for(int i = 0; i < wordList.size(); i++)
            {
                if(dist[i] != 0)continue;
                if(check[tmp][i])
                {
                    if(i == end)return dist[tmp] + 1;
                    dist[i] = dist[tmp] + 1;
                    q.push(i);
                }
            }
        }
        return 0;
    }
};

/*
116ms
解法2：朴素BFS搜索 + 优化查找下一节点
time : O(N)线性时间  
space : O(N^2)
note : unordered_set 可在 O(1) 时间内实现 增、删、查

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordlist;
        bool flag = false;
        for(int i = 0; i < wordList.size(); i++)
        {
            wordlist.insert(wordList[i]);
            if(wordList[i] == endWord)flag = true;
        }
        if(!flag)return 0;
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        while(q.size())
        {
            pair<string, int>tmp = q.front();
            string str = tmp.first;
            int depth = tmp.second;
            q.pop();
            for(int i = 0; i < str.size(); i++)
            {
                for(char cha = 'a'; cha <= 'z'; cha ++)
                {
                    string newstr = str;
                    newstr[i] = cha;
                    if(newstr == endWord)return depth + 1;
                    if(wordlist.count(newstr))
                    {
                        q.push({newstr, depth + 1});
                        wordlist.erase(newstr);
                    }
                }
            }
        }
        
        return 0;
    }
};

/*
解法2：双端队列优化版BFS + 优化查找下一节点
time : 指数倍减少
space : 
28 ms
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordlist;
        unordered_map<string, int> wordlist1, wordlist2;
        bool flag = false;
        for(int i = 0; i < wordList.size(); i++)
        {
            wordlist.insert(wordList[i]);
            if(wordList[i] == endWord)flag = true;
        }
        if(!flag)return 0;
        queue<string>q, rq;
        q.push(beginWord);
        wordlist1[beginWord] = 1;
        rq.push(endWord);
        wordlist2[endWord] = 1;
        wordlist.erase(beginWord), wordlist.erase(endWord);  //防止wordlist里面有这些数组，导致wordlist1, wordlist2 的距离被自己更新（+1）
        while(q.size() && rq.size())
        {
            if(q.size() <= rq.size())
            {
                string str = q.front();
                q.pop();
                for(int i = 0; i < str.size(); i++)
                {
                    for(char cha = 'a'; cha <= 'z'; cha ++)
                    {
                        string newstr = str;
                        newstr[i] = cha;
                        if(wordlist2.count(newstr))
                        {
                            return wordlist1[str] + wordlist2[newstr];
                        }
                        if(wordlist.count(newstr))
                        {
                            q.push(newstr);
                            wordlist1[newstr] = wordlist1[str] + 1;
                            wordlist.erase(newstr);
                        }
                    }
                }
            }
            else
            {
                string str = rq.front();
                rq.pop();
                for(int i = 0; i < str.size(); i++)
                {
                    for(char cha = 'a'; cha <= 'z'; cha ++)
                    {
                        string newstr = str;
                        newstr[i] = cha;
                        if(wordlist1.count(newstr))
                        {
                            return wordlist2[str] + wordlist1[newstr];
                        }
                        if(wordlist.count(newstr))
                        {
                            rq.push(newstr);
                            wordlist2[newstr] = wordlist2[str] + 1;
                            wordlist.erase(newstr);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};

/*
解法3：A* BFS
time : 
space : 
124ms
*/
class Solution {
public:
    int distance(string a, string b)
    {
        int cnt = 0;
        for(int i = 0; i < a.size(); i++)
            if(a[i] != b[i])cnt ++;
        return cnt;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordlist;
        unordered_map<string, int>dist;
        bool flag = false;
        for(int i = 0; i < wordList.size(); i++)
        {
            wordlist.insert(wordList[i]);
            if(wordList[i] == endWord)flag = true;
        }
        if(!flag)return 0;
        
        priority_queue<pair<int, string>>q;
        q.push({- 1 - distance(beginWord, endWord), beginWord});
        dist[beginWord] = 1;
        while(q.size())
        {
            pair<int, string>tmp = q.top();
            string str = tmp.second;
            q.pop();
            for(int i = 0; i < str.size(); i++)
            {
                for(char cha = 'a'; cha <= 'z'; cha ++)
                {
                    string newstr = str;
                    newstr[i] = cha;
                    if(newstr == endWord)
                    {
                        // cout<<str<<" "<<dist[str]<<endl;
                        return dist[str] + 1;
                    }
                    if(wordlist.count(newstr) && dist.count(newstr) == 0)
                    {
                        dist[newstr] = dist[str] + 1;
                        q.push({ - dist[newstr] - distance(newstr, endWord), newstr});
                        wordlist.erase(newstr);
                    }
                }
            }
        }
        
        return 0;
    }
};

