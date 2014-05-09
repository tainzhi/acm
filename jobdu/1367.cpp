/*************************************************************************
    > File: jobdu 1367
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Sun 23 Feb 2014 09:28:25 AM CST
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

bool isBinarySearchTree(int start, int end, int *node)
{
    if (start == end || start + 1 == end)
        return true;
    else if (start + 1 < end)
    {
        int flag = true;
        int mid = -1;
        for (int i=start; i<end; i++)
        {
            if (node[i] < node[end])
                mid = i;
            else 
                break;
        }
        if (mid == -1)
        {
            for (int i=start; i<end; i++)
                if (node[i] < node[end])
                    return false;
            return isBinarySearchTree(start, end-1, node);
        }
        for (int i=mid+1; i<end; i++)
            if (node[i] < node[end])
                return false;
        if (mid+1<= end -1)
            return isBinarySearchTree(start,mid, node) && isBinarySearchTree(mid+1, end-1, node);
        else
            return isBinarySearchTree(start, mid, node);
    }
}

int main()
{
    int node[10010];
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d", &node[i]);
        if (isBinarySearchTree(0, n-1, node))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}


