/*************************************************************************
    > File: jobdu 1517
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 12:22:27 PM CST
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
    int n, k;
    struct node {
        int data;
        struct node * next;
    };
    while (scanf("%d%d", &n, &k) != EOF)
    {
        node * root = (node *)malloc(sizeof(node));
        root->next = NULL;
        node * p = root;
        for (int i = 0; i < n; i++)
        {
            int st;
            scanf("%d", &st);
            p->next = (node *)malloc(sizeof(node));
            p->next->data = st;
            p->next->next = NULL;
            p = p->next;
        }
        /*
        node * pt = root->next;
        while (pt)
        {
            printf("**%d**", pt->data);
            pt = pt->next;
        }
        */
        node * q = NULL;
        p = root;
        while (p && k--)
            p = p->next;
        //printf("------%d---%d\n", p->data, root->next->data);
        if (p)
        {
            q = root->next;
            while (p->next)
            {
                q = q->next;
                p = p->next;
            }
        }
        if (q)
            printf("%d\n", q->data);
        else
            printf("NULL\n");
    }
    return 0;
}



