/*************************************************************************
    > File: jobdu 1518
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 01:03:56 PM CST
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
    struct node {
        int data;
        struct node * pre;
        struct node * post;
    };
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            printf("NULL\n");
        else
        {
            int st;
            node * root = (node *)malloc(sizeof(node));
            scanf("%d", &st);
            root->data = st;
            root->pre = root->post = NULL;
            node * p = root;
            for (int i = 1; i < n; i++)
            {
                p -> post = (node *)malloc(sizeof(node));
                scanf("%d", &st);
                p -> post -> data = st;
                p -> post -> post = NULL;
                p -> post -> pre = p;
                p = p -> post;
            }
            while (p->pre)
            {
                printf("%d ", p->data);
                p = p -> pre;
            }
            if (p->pre == NULL)
                printf("%d\n", p->data);
        }
    }
    return 0;
}

