# Stack

> tips

单调栈：给定一个序列，对于序列中的数，找到左边 / 右边 **距离最近** 的数在什么地方


## 496. Next Greater Element I

> Approach1: Stack

```c++
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size() == 0 || nums2.size() == 0)return res;
        stack<int>stk;
        unordered_map<int, int>hash;
        for(int i = nums2.size() - 1; i >= 0; i --)
        {
            while(stk.size() && stk.top() < nums2[i])stk.pop();
            int t = stk.size() ? stk.top() : -1;
            hash[nums2[i]] = t;
            stk.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i ++)
          	res.push_back(hash[nums1[i]]);
        return res;
    }
};
```

## 456. 132 Pattern

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


