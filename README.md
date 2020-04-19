# Info

some notes about my acm training and problems Solutions

- [Notes](#notes)
- [Solutions](#solutions)
    - [jobdu](#jobdu)
    - [hdu](#hdu)
    - [poj](#poj)
    - [UVA](#uva)
    - [Codechef](#codechef)
    - [SPOJ](#spoj)
## 基础算法
- 冒泡排序
- 快速排序，[912：排序数组](https://leetcode-cn.com/problems/sort-an-array/)
- 归并排序
- 插入排序, 二分插入排序
- 选择排序
- shell排序
- 计数排序 counting sort
- 基数排序 radix sort
- 桶排序bucket sort
- 堆排序 heap_sort

## 针对面试
### 双指针
- [Easy][167: two sum II](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/submissions/)
- [Easy][633: Sum of Square Numbers](https://leetcode-cn.com/problems/sum-of-square-numbers/): 使用unsigend int; Math.sqrt剪枝
- [Easy][345: Reverse Vowels of a String](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)
- [Medidum][345: Reverse Vowels of a String](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)
- [Easy][88: Merge Sorted Array](https://leetcode-cn.com/problems/merge-sorted-array/)
- [Easy][141: Linked List Cycle](https://leetcode-cn.com/problems/linked-list-cycle/): 双指针, 一个指针跳一步, 另一个指针跳2步, 若存在环, 则一定能相遇
- [Medium][524: Longest Word in Dictionary through Deleting](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/): 用指针判断另一个string是否是当前string的字串, 即另一个string的char与当前string的char相等, 另一个string的指针才增加直到遍历完
### 排序
- [Medium][347. Top K Frequent Elements](https://leetcode-cn.com/problems/top-k-frequent-elements/)
- [Medium][451. Sort Characters By Frequency](https://leetcode-cn.com/problems/sort-characters-by-frequency/): 根据char出现的频率倒序排序, 然后输出
- [Medium][75. Sort Colors, 三色旗排序](https://leetcode-cn.com/problems/sort-colors/): 也可以插入排序; 当然还有三色旗的特定解法

### 链表指针
- [1. Two Sum](https://leetcode-cn.com/problems/two-sum/)
- [160. Intersection of Two Linked Lists](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/): 暴力法和双指针法: 两个指针分别从头同步遍历, 如果到达链表尾后, 切换到另一个链表头, 依然同步遍历, 如果相等, 则是交点, 否则到达末尾, 返回NULL
- [206. Reverse Linked List (Easy)](https://leetcode-cn.com/problems/reverse-linked-list/description/)
- [21. Merge Two Sorted Lists](https://leetcode-cn.com/problems/merge-two-sorted-lists/description/)
- [83. Remove Duplicates from Sorted List](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)
- [Medium][: 19. Remove Nth Node From End of List](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/): 双指针, 第2个指针比第一个指针先走n步, 注意边界情况
- [Medium][24. Swap Nodes in Pairs](https://leetcode-cn.com/problems/swap-nodes-in-pairs/): 交换链表相邻两个节点
- [Medium][147. Insertion Sort List](https://leetcode-cn.com/problems/insertion-sort-list/): 链表实现插入排序

### 堆和链表
- [Medium][445. Add Two Numbers II](https://leetcode-cn.com/problems/add-two-numbers-ii/)

### leetcode-cn
- leetcode-cn: 1, 147, 458, 530
- [1.Tow sum](https://leetcode-cn.com/problems/two-sum/)
- [19. Remove Nth Node From End of List](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)
- [21. Merge Two Sorted Lists](https://leetcode-cn.com/problems/merge-two-sorted-lists/description/)
- [24. Swap Nodes in Pairs](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)
- [75. Sort Colors](https://leetcode-cn.com/problems/sort-colors/)
- [83. Remove Duplicates from Sorted List](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)
- [88: Merge Sorted Array](https://leetcode-cn.com/problems/merge-sorted-array/)
- [141: Linked List Cycle](https://leetcode-cn.com/problems/linked-list-cycle/)
- [147. Insertion Sort List](https://leetcode-cn.com/problems/insertion-sort-list/)
- [160. Intersection of Two Linked Lists](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)
- [167: two sum II](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/submissions/)
- [206. Reverse Linked List (Easy)](https://leetcode-cn.com/problems/reverse-linked-list/description/)
- [345: Reverse Vowels of a String](https://leetcode-cn.com/problems/reverse-vowels-of-a-string/)
- [347. Top K Frequent Elements](https://leetcode-cn.com/problems/top-k-frequent-elements/)
- [451. Sort Characters By Frequency](https://leetcode-cn.com/problems/sort-characters-by-frequency/)
- [524: Longest Word in Dictionary through Deleting](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)
- [633: Sum of Square Numbers](https://leetcode-cn.com/problems/sum-of-square-numbers/)
- [912：排序数组](https://leetcode-cn.com/problems/sort-an-array/)


## 其他的一些笔记
### 删除除README和源码外的所有程序
```bash
# 用fd找到可执行程序删除
fd -x t |xargs rm -rf
# 用fd找到文件名包含dSYM文件夹删除
fd dSYM |xargs rm -rf
```
### compile and debug in MacOs
```bash
// 当前目录生成a.out可执行文件
clang++ a.cc

// 当前目录下生成可调式执行程序a.out
clang++ -g a.cc
// 用lldb打开a.out就可以调试了
lldb ./a.out
```

### Auto compile with bash

add following to `test.sh`

```
g++ $1
./a.out<a.in
```

how to use `test.sh`

```
. test.sh file.cc
sh test.sh file.cc
```

### Auto compile file and auto input data with vim
add following to your `$VIMRUNTIM/vimrc`

```
" make
set makeprg=g++\ -Wall\ \ %
nmap <silent> <F6> :make<CR><CR>
nmap <silent> <F7> :call Do_Make()<CR>
function! Do_Make()
    execute "!./a.out < a.in"
endfunction
```

- `<F6>`: compile current file, then get a.out
- `<F7>`: input a.in into a.out
- `a.in`: test data

### About c/c++

- sizeof()
```
int nums[10];
printf("%d %d", (int)sizeof(nums), (int)sizeof(int) * 10);
```
the result is `40 40`, that means that `sizeof(nums)` equals `sizeof(int) * 10`


- memset()
```
int nums[10];
memset(nums, 0, sizeof(nums));  //set every number in nums to 0
memset(nums, -1, sizeof(nums)); //set every number in nums to -1
memset(nums, 0xff, sizeof(nums)); //set every number in nums to -1
```

- max unsigend long long is 64bit, 0xffffffffffffffff, 大于`1.84*10^20`

## hdu
----
#### [HDU1176](https://vjudge.net/problem/HDU-1176) [Easy]动态规划
#### [HDU1241](https://vjudge.net/problem/HDU-1241) 深度优先搜索DFS
#### [HDU1312](https://vjudge.net/problem/HDU-1312) 深度优先搜索DFS
#### [HDU1421](https://vjudge.net/problem/HDU-1421) 动态规划
#### [HDU2204](https://vjudge.net/problem/HDU-1421) 容斥原理
#### [HDU3068](https://vjudge.net/problem/HDU-3068) [Medium]最长回文串Manacher算法
#### [HDU3696](https://vjudge.net/problem/HDU-3696) DFS+拓扑排序(或者DFS)
#### [HDU4105](https://vjudge.net/problem/HDU-4105) [Medium]动态规划
#### [HDU4109](https://vjudge.net/problem/HDU-4109) 关键路径AOE(Activity On Edge)
#### [HDU4635](https://vjudge.net/problem/HDU-4635) 强连通分量Targan



## jobdu
---
#### [jobdu1000](http://ac.jobdu.com/problem.php?pid=1000) oj入门简单题
#### [jobdu1008](http://ac.jobdu.com/problem.php?pid=1008) 单元最短路劲Dijkstra,使用邻接列表
#### [jobdu1009](http://ac.jobdu.com/problem.php?pid=1009) 二叉搜索树/BST Binary Search Tree
#### [jobdu1011](http://ac.jobdu.com/problem.php?pid=1011) Easy动态规划, 最大连续子序列
#### [jobdu1077](http://ac.jobdu.com/problem.php?pid=1077) Easy动态规划, 最大连续子序列, 包含负数, 使用int64
#### [jobdu1012](http://ac.jobdu.com/problem.php?pid=1012) 并查集
#### [jobdu1017](http://ac.jobdu.com/problem.php?pid=1017) 最小生成树Kruskal
#### [jobdu1018](http://ac.jobdu.com/problem.php?pid=1018) 简单题, 使用堆来统计
#### [jobdu1019](http://ac.jobdu.com/problem.php?pid=1019) 逆波兰表达式和一行多个单词的输入
#### [jobdu1024](http://ac.jobdu.com/problem.php?pid=1024) 最小生成树Prim minium spanning tree求最小值, 注意重复边的输入
#### [jobdu1027](http://ac.jobdu.com/problem.php?pid=1027) 欧拉回路 Eulerian Path
#### [jobdu1028](http://ac.jobdu.com/problem.php?pid=1028) 最小生成树, 并查集
#### [jobdu1041](http://ac.jobdu.com/problem.php?pid=1041) 简单排序然后去重题, 但要注意输出末尾无空格
#### [jobdu1067](http://ac.jobdu.com/problem.php?pid=1067) 简单题, 求阶乘, 递归
#### [jobdu1073](http://ac.jobdu.com/problem.php?pid=1073) 简单题, 递归打印杨辉三角
#### [jobdu1112](http://ac.jobdu.com/problem.php?pid=1112) Easy动态规划, 最长非增非连续子序列
#### [jobdu1120](http://ac.jobdu.com/problem.php?pid=1120) 全排列, 用c++ STL 的next_permutation(str, str + len)实现,不要使用string, 会TLE
#### [jobdu1140](http://ac.jobdu.com/problem.php?pid=1140) 八皇后Eight Queens Puzzle
#### [jobdu1172](http://ac.jobdu.com/problem.php?pid=1172) 哈弗曼树和小根堆 Huffeman Tree and min-heaps/max-heaps
#### [jobdu1176](http://ac.jobdu.com/problem.php?pid=1176) 完全二叉树第n层的节点数
#### [jobdu1182](http://ac.jobdu.com/problem.php?pid=1182) 简单题, 但要使用fgets
#### [jobdu1184](http://ac.jobdu.com/problem.php?pid=1184) 由先序遍历字符串生成二叉树
#### [jobdu1185](http://ac.jobdu.com/problem.php?pid=1185) 排序
#### [jobdu1186](http://ac.jobdu.com/problem.php?pid=1186) 闰年 Leap Year
#### [jobdu1201](http://ac.jobdu.com/problem.php?pid=1201) 二叉排序树/BST Binary Sort Tree
#### [jobdu1205](http://ac.jobdu.com/problem.php?pid=1205) Easy动态规划, int64
#### [jobdu1214](http://ac.jobdu.com/problem.php?pid=1214) [Medium]状态dp
#### [jobdu1283](http://ac.jobdu.com/problem.php?pid=1283) [Easy]字符串
#### [jobdu1335](http://ac.jobdu.com/problem.php?pid=1335) [Easy]BFS
#### [jobdu1341](http://ac.jobdu.com/problem.php?pid=1341) 单源最短路径Dijkstra,使用邻接矩阵
#### [jobdu1342](http://ac.jobdu.com/problem.php?pid=1342) 栈, 匹配的括号数
#### [jobdu1343](http://ac.jobdu.com/problem.php?pid=1343) 弗洛伊德变种Floyd
#### [jobdu1347](http://ac.jobdu.com/problem.php?pid=1347) 最小生成树Kruskal+并查集
#### [jobdu1348](http://ac.jobdu.com/problem.php?pid=1348) 归并排序求逆序对,结果是long long int
#### [jobdu1349](http://ac.jobdu.com/problem.php?pid=1349) 二分法
#### [jobdu1350](http://ac.jobdu.com/problem.php?pid=1350) [Easy]二叉树建树, 求深度
#### [jobdu1351](http://ac.jobdu.com/problem.php?pid=1351) [Easy]位运算
#### [jobdu1352](http://ac.jobdu.com/problem.php?pid=1352) [Easy]两数之和
#### [jobdu1369](http://ac.jobdu.com/problem.php?pid=1369) 全排列 Permutate
#### [jobdu1404](http://ac.jobdu.com/problem.php?pid=1404) BFS求有条件的最短路径
#### [jobdu1406](http://ac.jobdu.com/problem.php?pid=1406) 最短路劲条数, Dijkstra
#### [jobdu1408](http://ac.jobdu.com/problem.php?pid=1408) Easy动态规划
#### [jobdu1411](http://ac.jobdu.com/problem.php?pid=1411) Dijkstra求最短回路
#### [jobdu1417](http://ac.jobdu.com/problem.php?pid=1417) 最小生成树, Kruskal, STL map<>标记点的id
#### [jobdu1448](http://ac.jobdu.com/problem.php?pid=1448) 拓扑排序



## poj
---
#### [poj1185](http://poj.org/problem?id=1185) [Medium]状态DP
#### [poj1236](http://poj.org/problem?id=1236) 有向图的联通分量与联通图的缩点
#### [poj1837](http://poj.org/problem?id=1837) [Medium]动态规划
#### [poj1947](http://poj.org/problem?id=1947) [Medium]树型DP
#### [poj2186](http://poj.org/problem?id=2186) 有向图的联通分量与联通图的缩点
#### [poj2367](http://poj.org/problem?id=2367) 简单拓扑排序
#### [poj2407](http://poj.org/problem?id=2407) 欧拉函数
#### [poj2478](http://poj.org/problem?id=2478) 欧拉函数
#### [poj2773](http://poj.org/problem?id=2773) 容斥原理+二分法
#### [poj3311](http://poj.org/problem?id=3311) TSP(Travelling salesman problem)+状态DP
#### [poj3461](http://poj.org/problem?id=3461) KMP
#### [poj3904](http://poj.org/problem?id=3904) 容斥原理
#### [poj3974](http://poj.org/problem?id=3974) 最长回文串Manacher算法
### UVA
---
#### [uva10325](https://vjudge.net/problem/UVA-10325) 容斥原理, 使用long long
#### [uva11806](https://vjudge.net/problem/UVA-11806) 容斥原理

## Codechef
#### [COUNTREL](https://www.codechef.com/problems/COUNTREL) [Medium]容斥原理+数论模运算

## SPOJ
#### [ASSIGN-Assignments](http://www.spoj.com/problems/ASSIGN/en/) [Easy]状态DP, 使用滚动数组和位来表示状态
