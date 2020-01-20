# Binary Search

> tips

- 
- 



## 240. Search a 2D Matrix II

> Approach1: Brute-Force

```c++
//time : O(N^2)
//space : O(1)
```

> Approach2: Binary Search

```c++
//time : O(log(N!))
//space : O(1)
class Solution {
public:
    bool check(vector<vector<int>>& matrix, int target, int diag)
    {
        int n = matrix.size(), m = matrix[0].size();
        //check row
        int l = diag, r = m - 1;
        while(l < r)
        {
            int mid = l + r + 1>> 1;
            if(matrix[diag][mid] == target)return true;
            else if(matrix[diag][mid] > target) r = mid - 1;
            else l = mid;
        }
        if(matrix[diag][l] == target)return true;
        //check collumn
        l = diag, r = n - 1;
        while(l < r)
        {
            int mid = l + r + 1>> 1;
            if(matrix[mid][diag] == target)return true;
            else if(matrix[mid][diag] > target) r = mid - 1;
            else l = mid;
        }
        if(matrix[l][diag] == target)return true;
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)return false;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < min(n, m); i++)
        {
            if(check(matrix, target, i))
                return true;
        }
        return false;
    }
};
```

> Approach3: Divide and Conquer

```c++
//下次再看，有点麻烦
```


> Approach4: Search Space Reduction

```c++
//time : O(N + M)
//space : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)return false;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0)
        {
            if(matrix[i][j] == target)return true;
            else if(matrix[i][j] < target) i++;
            else j --;
        }
        return false;
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


