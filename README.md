#Info
some notes about my acm training and problems Solutions
- [Notes](#notes)
- [Solutions](#solutions)
    - [jobdu](#jobdu)
    - [hdoj](#hdoj)
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



##hdoj
----
####2204
指数为素数,dfs实现容斥原理,只有因为2^(2*3*5*7*)=2*60大于10^18,所以只用枚举
60以内至多三种素数的组合情况


自我实现两个关键字的排序：two keys, 如果当key２相同时，比较key1, 那么分别先对key1排序，然后再对key2排序


二叉搜索树建树

##jobdu
---
####[jobdu1000](http://ac.jobdu.com/problem.php?pid=1000) oj入门简单题
####[jobdu1008](http://ac.jobdu.com/problem.php?pid=1008) 单元最短路劲Dijkstra,使用邻接列表
####[jobdu1009](http://ac.jobdu.com/problem.php?pid=1009) 二叉搜索树/BST Binary Search Tree
####[jobdu1012](http://ac.jobdu.com/problem.php?pid=1012) 并查集
####[jobdu1017](http://ac.jobdu.com/problem.php?pid=1017) 最小生成树Kruskal
####[jobdu1018](http://ac.jobdu.com/problem.php?pid=1018) 简单题, 使用堆来统计
####[jobdu1019](http://ac.jobdu.com/problem.php?pid=1019) 逆波兰表达式和一行多个单词的输入
####[jobdu1027](http://ac.jobdu.com/problem.php?pid=1027) 欧拉回路 Eulerian Path
####[jobdu1041](http://ac.jobdu.com/problem.php?pid=1041) 简单排序然后去重题, 但要注意输出末尾无空格
####[jobdu1172](http://ac.jobdu.com/problem.php?pid=1172) 哈弗曼树和小根堆 Huffeman Tree and min-heaps/max-heaps
####[jobdu1176](http://ac.jobdu.com/problem.php?pid=1176) 完全二叉树第n层的节点数
####[jobdu1182](http://ac.jobdu.com/problem.php?pid=1182) 简单题, 但要使用fgets
####[jobdu1184](http://ac.jobdu.com/problem.php?pid=1184) 由先序遍历字符串生成二叉树
####[jobdu1185](http://ac.jobdu.com/problem.php?pid=1185) 排序
####[jobdu1186](http://ac.jobdu.com/problem.php?pid=1186) 闰年 Leap Year
####[jobdu1201](http://ac.jobdu.com/problem.php?pid=1201) 二叉排序树/BST Binary Sort Tree
####[jobdu1341](http://ac.jobdu.com/problem.php?pid=1341) 单源最短路径Dijkstra,使用邻接矩阵
####[jobdu1343](http://ac.jobdu.com/problem.php?pid=1343) 弗洛伊德变种Floyd
####[jobdu1369](http://ac.jobdu.com/problem.php?pid=1369) 全排列 Permutate
####[jobdu1406](http://ac.jobdu.com/problem.php?pid=1406) 最短路劲条数, Dijkstra



##poj
---
####[poj3461](http://poj.org/problem?id=3461) KMP

##leetcode
---
[leetcode1](https://leetcode.com/problems/two-sum/?tab=Description) Two Sum
[leetcode147](https://leetcode.com/problems/insertion-sort-list/?tab=Description) Insertion Sort List
