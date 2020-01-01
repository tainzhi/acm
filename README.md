# Info

some notes about my acm training and problems Solutions

- [Notes](#notes)
- [Solutions](#solutions)
    - [jobdu](#jobdu)
    - [hdu](#hdu)
    - [poj](#poj)
    - [leetcode](#leetcode)
    - [UVA](#uva)
    - [Codechef](#codechef)
    - [SPOJ](#spoj)
## 基础算法
- 冒泡排序
- 快速排序，[力扣912：排序数组](https://leetcode-cn.com/problems/sort-an-array/)
- 归并排序
- 插入排序, 二分插入排序
- 选择排序
- shell排序
- 计数排序 counting sort
- 基数排序 radix sort
- 桶排序bucket sort
- 堆排序 heap_sort

### 力扣leetcode-cn
- [力扣912：排序数组](https://leetcode-cn.com/problems/sort-an-array/)

## notes
----

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

## leetcode
---
#### [leetcode1](https://leetcode.com/problems/two-sum/?tab=Description) Two Sum
#### [leetcode530](https://leetcode.com/problems/minimum-absolute-difference-in-bst/#/description) Minimum Absolute Difference in BST

### UVA
---
#### [uva10325](https://vjudge.net/problem/UVA-10325) 容斥原理, 使用long long
#### [uva11806](https://vjudge.net/problem/UVA-11806) 容斥原理

## Codechef
#### [COUNTREL](https://www.codechef.com/problems/COUNTREL) [Medium]容斥原理+数论模运算

## SPOJ
#### [ASSIGN-Assignments](http://www.spoj.com/problems/ASSIGN/en/) [Easy]状态DP, 使用滚动数组和位来表示状态
