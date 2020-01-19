# Linked List

> tips

- 若有可能删除头结点，则需要创建虚拟节点指向头结点
- 翻转可通过改变节点value，也可通过改变节点next指针



## 19. Remove Nth Node From End of List

“Dummy” pointer is used to simplify some corner cases, such as a list with only one node, or removing the head of list

> Approach1: two pass algorithm

Time: O(L), L means the size / length of linked list

Space: O(1), just a dummy node

First go through all the list, find out the length of list L;

Second find the (L-n)-th node, and delete its next node.

> Approach2: one pass algorithm with O(L) space complexity

Time: O(L)

Space: O(L), vector to record every node in list

First go through all the list, record all the node in vector, delete the Nth node from end of list.

> Approach3: one pass algorithm with 2 pointers

Time: O(L)

Space: O(1), just a dummy node, 2 pointer: first, second

First let pointer “first” go n step from the head of list, then “let second” points to the head of list;

Then let 2 pointers keep going until “first” meet the end of list, then just remove the node after “second”. 



## 237. Delete Node in a Linked List

> Approach1: swap with next node

Time: O(1)

Space: O(1)

The usual way of deleting a node from a linked list is to modify the next pointer of the node before it, to point to the node after it. However, since we do not access to the node before the one we want to delete, then we have to replace the value of the node we want to delete with the value int the node after it, and then delete the node after it.



## **206.** Reverse Linked List

> Approach1: Iterative

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL)return head;
        
        ListNode *a = head, *b = a -> next;
        while(b != NULL)
        {
            auto c = b -> next;
            b -> next = a;
            a = b, b = c;
        }
        head -> next = NULL;
        
        return a;
    }
};
```

> Approach1: Recursive

```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL)return head;
        
        ListNode *tmp = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return tmp;
    }
};
```



## 148. Sort List

> Approach1: Iterative

```c++

```



> Approach1: Recursive

```c++
https://www.acwing.com/solution/LeetCode/content/85/
```





## 143. Reorder List

> Approach1: O(N^2)

```c++
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head -> next)return ;
        
        int n = 0;
        for(auto p = head; p; p = p -> next)n ++;
        
        auto curr = head;
        for(int i = 1; i <= n / 2; i ++)
        {
            auto ne = curr -> next;
            auto p = curr;
            for(int j = i; i + j <= n; j++)
                p = p -> next;
            p -> next = ne;
            curr -> next = p;
            curr = curr -> next -> next;
        }
        curr -> next = NULL;
        return ;
    }
};
```

> Approach1: O(N)

```c++
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head -> next)return ;
        
        int n = 0;
        for(auto p = head; p; p = p -> next)n ++;
        
        if(n <= 2)return ;
        
        ListNode *last, *curr = head;
        for(int i = 1; i < (n + 1) / 2; i ++)
            curr = curr -> next;
        
        auto a = curr, b = curr -> next;
        a -> next = NULL;
        
        while( b!= NULL)
        {
            auto c = b -> next;
            b -> next = a;
            a = b, b = c;
        }
        last = a;
        cout<<last->val<<endl;
        
        curr = head;
        for(int i = 1; i <= n / 2; i++)
        {
            auto newlast = last -> next;
            last -> next = curr -> next;
            curr -> next = last;
            curr = curr -> next -> next;
            last = newlast;
        }
        return ;
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


