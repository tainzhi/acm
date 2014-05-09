/*************************************************************************
    > File: 
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 11:52:17 AM CST
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

int n;
int array[1000010];
int odd[1000010];
int even[1000010];

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &array[i]);
    int oddC =0, evenC=0;
    for (int i = 0; i<n; i++)
        if (array[i] % 2)
            odd[oddC++] = array[i];
        else
            even[evenC++] = array[i];
    for (int i = 0; i < oddC; i++)
        printf("%d%c", odd[i], ((i == oddC - 1) && (evenC == 0)) ? '\n' : ' ');
    if (evenC > 0)
    {
        for (int i = 0; i < evenC; i++)
            printf("%d%c", even[i], i == evenC-1 ? '\n': ' ');
    }
    return 0;
}
