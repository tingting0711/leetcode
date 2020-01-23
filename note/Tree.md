# Tree

> tips

- 


## 98. Validate Binary Search Tree

> Approach1: Iterative

```c++
/*
1. 将整棵树的最左边一条链压入栈中
2. 每次取出栈顶元素，如果他有右子树，则将右子树压入栈
*/
```

> Approach2: Recursive top2buttom

```c++
class Solution {
public:
    bool dfs(TreeNode* x, long long min, long long max)
    {
        if(x->val <= min || x->val >= max)return false;
        if(x->left && !dfs(x->left, min, x->val))return false;
        if(x->right && !dfs(x->right, x->val, max))return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        long long INF = 9223372036854775807;
        return dfs(root, -INF, INF);
    }
};
```

> Approach3: Recursive buttom2top

```c++
class Solution {
public:
    
    bool dfs(TreeNode* root, int& minv, int& maxv)
    {
        minv = maxv = root->val;
        if(root->left)
        {
            int newMin, newMax;
            if(!dfs(root->left, newMin, newMax))return false;
            if(newMax >= root->val)return false;
            minv = newMin;
        }
        if(root->right)
        {
            int newMin, newMax;
            if(!dfs(root->right, newMin, newMax))return false;
            if(newMin <= root->val)return false;
            maxv = newMax;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;
        int minv, maxv;
        if(dfs(root, minv, maxv))return true;
        else return false;
    }
};
```


> Approach4: Inorder traversal

```c++

```




## 108. Convert Sorted Array to Binary Search Tree

> Approach1: Iterative

```c++

```

> Approach1: Recursive

```c++

```



## 94. Binary Tree Inorder Traversal

> Approach1: Iterative 递归改非递归

```c++
/*
可以用栈来模拟这个过程。栈中每个元素存储两个值：TreeNode节点和一个整型的标记。
标记 = 0，表示还没遍历该节点的左子树；
标记 = 1，表示已经遍历完左子树，但还没遍历右子树；
标记 = 2，表示已经遍历完右子树；

然后我们可以根据标记的值，来分别处理各种情况：
标记 = 0，则将该节点的标记改成1，然后将其左儿子压入栈中；
标记 = 1，则说明左子树已经遍历完，将根节点的值插入答案序列中，然后将该节点的标记改成2，并将右儿子压入栈中；
标记 = 2，则说明以该节点为根的子树已经遍历完，直接从栈中弹出即可；
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*, int>>sta;
        sta.push(make_pair(root, 0));
        while (!sta.empty())
        {
            if (sta.top().first == NULL)
            {
                sta.pop();
                continue;
            }
            int t = sta.top().second;
            if (t == 0)
            {
                sta.top().second = 1;
                sta.push(make_pair(sta.top().first->left, 0));
            }
            else if (t == 1)
            {
                res.push_back(sta.top().first->val);
                sta.top().second = 2;
                sta.push(make_pair(sta.top().first->right, 0));
            }
            else sta.pop();
        }
        return res;
    }
};
```

> Approach1: Recursive

```c++

```



## 题目

> Approach1: Iterative

```c++

```

> Approach1: Recursive

```c++

```



## 题目

> Approach1: Iterative

```c++

```

> Approach1: Recursive

```c++

```



## 题目

> Approach1: Iterative

```c++

```

> Approach1: Recursive

```c++

```



## 题目

> Approach1: Iterative

```c++

```

> Approach1: Recursive

```c++

```



## 题目

> Approach1: Iterative

```c++

```

> Approach1: Recursive

```c++

```



## 题目

> Approach1: Iterative

```c++

```

> Approach1: Recursive

```c++

```


