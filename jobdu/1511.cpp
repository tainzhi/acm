/*************************************************************************
    > File: jobdu1511
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Tue 18 Feb 2014 10:55:23 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

int main()
{
    int num;
    struct link {
        int data;
        struct link * before;
        struct link * next;
    };
    link * start = NULL, * p;
    while (true)
    {
        scanf("%d", &num);
        if (num == -1)
            break;
        p = (link *)malloc(sizeof(link));
        p->data = num;
        p->before = start;
        p->next = NULL;
        start = p;
    }
    while (p)
    {
        printf("%d\n", p->data);
        p = p -> before;
    }
    return 0;
}




