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

#####1014
`fgets`换行符`\n`使得停止读取，同时把换行符'\n'作为有效字符添加到字串末尾，同时添加字串结束符`\0`
```
#include <stdio.h>

char buffer[100];
while (fgets(buffer, 100, stdin) != NULL) {
    if ((int)strlen(buffer) == 1 && buffer[1] =='\n')
        break;
}

`gets()`在c99废除，因为未制定大小，容易导致溢出错误
```

自我实现两个关键字的排序：two keys, 如果当key２相同时，比较key1, 那么分别先对key1排序，然后再对key2排序

#####1186
闰年leap year判断, 还是common year; 闰年2月有29
```
bool IsLeapYear(int year) {
    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
        return  true;
    else
        return false;
}
```

输出4位, 高位不足补零, 比如1输出0001
```
printf("%04d", year);
```

####1009
`scanf("%d", &n)`与`fgets(str, 100, stdin)`不能同时使用, 因为scanf不会读到`\n`, 而fgets会读到`\n`.

推荐`scan("%d", &n)`与`scanf("%s", str)`

`puts(str)`会在字符串末尾输出`\n`换行符

二叉搜索树建树
