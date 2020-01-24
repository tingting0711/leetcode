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



## 144. Binary Tree Preorder Traversal

> Approach1: Iterative

```c++
class Solution {
public:
    vector<int>res;
    void dfs(TreeNode* root)
    {
        if(!root)return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)return res;
        dfs(root);
        return res;
    }
};
```

> Approach2: Recursive

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root == NULL)return res;
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* t = stk.top();
            stk.pop();
            res.push_back(t -> val);
            if(t -> right)stk.push(t -> right);
            if(t -> left)stk.push(t -> left);
        }
        return res;
    }
};
```

> Approach3: BFS from top to buttom, from left to right

> Approach 4: Morris traversal

```c++
//优化额外空间为O(1)
```



## 105. Construct Binary Tree from Preorder and Inorder Traversal

- 重点题
- 需保证节点不重复，否则无法唯一确定树
- 姐妹题：106. Construct Binary Tree from Inorder and Postorder Traversal

> Approach1: Recursive

```c++
class Solution {
public:
    unordered_map<int, int>hash;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir)
    {
        if(pl > pr)return NULL;
        int val = preorder[pl];
        int k = hash[val] - il;
        TreeNode* root = new TreeNode(val);
        root -> left = dfs(preorder, inorder, pl + 1, pl + k, il, il + k - 1);
        root -> right = dfs(preorder, inorder, pl + k + 1, pr, il + k + 1, ir);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i ++)
            hash[inorder[i]] = i;
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
```



## 235. Lowest Common Ancestor of a Binary Search Tree

- 姐妹题：236. Lowest Common Ancestor of a Binary Tree

> Approach1: Iterative

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(curr)
        {
            if(curr -> val < p -> val && curr -> val < q -> val)
                curr = curr -> right;
            else if(curr ->val > p -> val && curr -> val > q -> val)
                curr = curr -> left;
            else return curr;
        }
        return curr;
    }
};
```

> Approach2: Recursive

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root -> val && q->val < root -> val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root -> val && q->val > root -> val)
            return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};
```



## 236. Lowest Common Ancestor of a Binary Tree

> Approach1: Iterative

```c++
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*>stk;
        unordered_map<TreeNode*, TreeNode*>hash;
        hash[root] = NULL;
        stk.push(root);
        while(!hash.count(p) || !hash.count(q))
        {
            auto t = stk.top();
            stk.pop();
            if(t -> left)
            {
                stk.push(t->left);
                hash[t->left] = t;
            }
            if(t -> right)
            {
                 stk.push(t->right);
                hash[t->right] = t;
            }
        }
        unordered_set<TreeNode*> parent;
        auto t = p;
        while(t != NULL)
        {
            parent.insert(t);
            t = hash[t];
        }
        t = q;
        while(!parent.count(t))
        {
            t = hash[t];
        }
        return t;
    }
};
```

> Approach2: Recursive

```c++
class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)return NULL;
        int left = dfs(root -> left, p, q) ? 1 : 0;
        int right = dfs(root -> right, p, q) ? 1 : 0;
        int mid = (root == p || root == q) ? 1 : 0;
        
        if(mid + left + right >= 2)
        {
            ans = root;
        }
        
        return (mid + left + right >= 1);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
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


