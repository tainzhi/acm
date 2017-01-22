####hdoj 2204


指数为素数,dfs实现容斥原理,只有因为2^(2*3*5*7*)=2*60大于10^18,所以只用枚举
60以内至多三种素数的组合情况


###leetcode
#####1
给出一组数,找出其中的两个数,使得其和满足指定值. 

该题很简单, 时间复杂度o(n*n)即可AC.

但要注意,使用C语言提交, 因为是函数返回int *, 所以要在函数体内声明, 使用`malloc`分配内存

```
include <stdlib.h>

int *result = (int *)malloc(sizeof(int) * 4);
free(result);       /*free the memory*/
```


###九度OJ
#####1179
阶乘, 需要使用`long long int`, 输出为`printf("%lld", n)

#####1181
- 插入排序InsertSort
- 选择排序SelectSort
- 冒泡排序BubbleSort
- 希尔排序ShellSort
- 快速排序QuickSort
- 堆排序StackSort
- 归并排序MergeSort
