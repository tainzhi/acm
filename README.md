#Info
some notes about my acm training and problems Solutions
- [Notes](#notes)
- [Solutions](#solutions)
    - [jobdu](#jobdu)
    - [hdu](#hdu)
    - [poj](#poj)
    - [leetcode](#leetcode)


##notes
----
###Auto compile with bash
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

###Auto compile file and auto input data with vim
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

###About c/c++

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



##hdu
----
####[HDU1241](https://vjudge.net/problem/HDU-1241) 深度优先搜索DFS
####[HDU1312](https://vjudge.net/problem/HDU-1312) 深度优先搜索DFS
####[HDU1421](https://vjudge.net/problem/HDU-1421) 动态规划
####[HDU3068](https://vjudge.net/problem/HDU-3068) 最长回文串Manacher算法
####[HDU4109](https://vjudge.net/problem/HDU-4109) 关键路径AOE(Activity On Edge)

####2204
指数为素数,dfs实现容斥原理,只有因为2^(2*3*5*7*)=2*60大于10^18,所以只用枚举
60以内至多三种素数的组合情况


自我实现两个关键字的排序：two keys, 如果当key２相同时，比较key1, 那么分别先对key1排序，然后再对key2排序



##jobdu
---
####[jobdu1000](http://ac.jobdu.com/problem.php?pid=1000) oj入门简单题
####[jobdu1008](http://ac.jobdu.com/problem.php?pid=1008) 单元最短路劲Dijkstra,使用邻接列表
####[jobdu1009](http://ac.jobdu.com/problem.php?pid=1009) 二叉搜索树/BST Binary Search Tree
####[jobdu1011](http://ac.jobdu.com/problem.php?pid=1011) Easy动态规划, 最大连续子序列
####[jobdu1077](http://ac.jobdu.com/problem.php?pid=1077) Easy动态规划, 最大连续子序列, 包含负数, 使用int64
####[jobdu1012](http://ac.jobdu.com/problem.php?pid=1012) 并查集
####[jobdu1017](http://ac.jobdu.com/problem.php?pid=1017) 最小生成树Kruskal
####[jobdu1018](http://ac.jobdu.com/problem.php?pid=1018) 简单题, 使用堆来统计
####[jobdu1019](http://ac.jobdu.com/problem.php?pid=1019) 逆波兰表达式和一行多个单词的输入
####[jobdu1024](http://ac.jobdu.com/problem.php?pid=1024) 最小生成树Prim minium spanning tree求最小值, 注意重复边的输入
####[jobdu1027](http://ac.jobdu.com/problem.php?pid=1027) 欧拉回路 Eulerian Path
####[jobdu1028](http://ac.jobdu.com/problem.php?pid=1028) 最小生成树, 并查集
####[jobdu1041](http://ac.jobdu.com/problem.php?pid=1041) 简单排序然后去重题, 但要注意输出末尾无空格
####[jobdu1067](http://ac.jobdu.com/problem.php?pid=1067) 简单题, 求阶乘, 递归
####[jobdu1073](http://ac.jobdu.com/problem.php?pid=1073) 简单题, 递归打印杨辉三角
####[jobdu1112](http://ac.jobdu.com/problem.php?pid=1112) Easy动态规划, 最长非增非连续子序列
####[jobdu1120](http://ac.jobdu.com/problem.php?pid=1120) 全排列, 用c++ STL 的next_permutation(str, str + len)实现,不要使用string, 会TLE
####[jobdu1140](http://ac.jobdu.com/problem.php?pid=1140) 八皇后Eight Queens Puzzle
####[jobdu1172](http://ac.jobdu.com/problem.php?pid=1172) 哈弗曼树和小根堆 Huffeman Tree and min-heaps/max-heaps
####[jobdu1176](http://ac.jobdu.com/problem.php?pid=1176) 完全二叉树第n层的节点数
####[jobdu1182](http://ac.jobdu.com/problem.php?pid=1182) 简单题, 但要使用fgets
####[jobdu1184](http://ac.jobdu.com/problem.php?pid=1184) 由先序遍历字符串生成二叉树
####[jobdu1185](http://ac.jobdu.com/problem.php?pid=1185) 排序
####[jobdu1186](http://ac.jobdu.com/problem.php?pid=1186) 闰年 Leap Year
####[jobdu1201](http://ac.jobdu.com/problem.php?pid=1201) 二叉排序树/BST Binary Sort Tree
####[jobdu1205](http://ac.jobdu.com/problem.php?pid=1205) Easy动态规划, int64
####[jobdu1341](http://ac.jobdu.com/problem.php?pid=1341) 单源最短路径Dijkstra,使用邻接矩阵
####[jobdu1342](http://ac.jobdu.com/problem.php?pid=1342) 栈, 匹配的括号数
####[jobdu1343](http://ac.jobdu.com/problem.php?pid=1343) 弗洛伊德变种Floyd
####[jobdu1347](http://ac.jobdu.com/problem.php?pid=1347) 最小生成树Kruskal+并查集
####[jobdu1369](http://ac.jobdu.com/problem.php?pid=1369) 全排列 Permutate
####[jobdu1406](http://ac.jobdu.com/problem.php?pid=1406) 最短路劲条数, Dijkstra
####[jobdu1408](http://ac.jobdu.com/problem.php?pid=1408) Easy动态规划
####[jobdu1411](http://ac.jobdu.com/problem.php?pid=1411) Dijkstra求最短回路
####[jobdu1417](http://ac.jobdu.com/problem.php?pid=1417) 最小生成树, Kruskal, STL map<>标记点的id
####[jobdu1448](http://ac.jobdu.com/problem.php?pid=1448) 拓扑排序



##poj
---
####[poj1236](http://poj.org/problem?id=1236) 有向图的联通分量与联通图的缩点
####[poj2367](http://poj.org/problem?id=2367) 简单拓扑排序
####[poj3461](http://poj.org/problem?id=3461) KMP
####[poj3974](http://poj.org/problem?id=3974) 最长回文串Manacher算法

##leetcode
---
####[leetcode1](https://leetcode.com/problems/two-sum/?tab=Description) Two Sum
####[leetcode147](https://leetcode.com/problems/insertion-sort-list/?tab=Description) Insertion Sort List
