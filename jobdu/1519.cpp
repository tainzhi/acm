/*************************************************************************
    > File: jobdu 1519
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 20 Feb 2014 01:43:20 PM CST
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
        struct node * next;
    };
    node * first = NULL, * second = NULL;
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        if (m == 0 && n == 0)
            printf("NULL\n");
        else if (m == 0 && n != 0)
        {
            int st;
            scanf("%d", &st);
            second = (node *)malloc(sizeof(node));
            second->data = st;
            second->next = NULL;
            node * p = second ;
            for (int i = 1; i < n; i++)
            {
                p->next = (node *)malloc(sizeof(node));
                scanf("%d", &st);
                p->next->data = st;
                p->next->next = NULL;
                p = p->next;
            }
            p = second;
            while (p->next)
            {
                printf("%d ", p->data);
                p = p -> next;
            }
            printf("%d\n", p->data);
        }
        else if (m != 0 && n == 0)
        {
            int st;
            scanf("%d", &st);
            first = (node *)malloc(sizeof(node));
            first->data = st;
            first->next = NULL;
            node * p = first ;
            for (int i = 1; i < m; i++)
            {
                p->next = (node *)malloc(sizeof(node));
                scanf("%d", &st);
                p->next->data = st;
                p->next->next = NULL;
                p = p->next;
            }
            p = first;
            while (p->next)
            {
                printf("%d ", p->data);
                p = p -> next;
            }
            printf("%d\n", p->data);
        }
        else
        {
            int st;
            scanf("%d", &st);
            first = (node *)malloc(sizeof(node));
            first->data = st;
            first->next = NULL;
            node * p = first;
            for (int i = 1; i < m; i++)
            {
                p->next = (node *)malloc(sizeof(node));
                scanf("%d", &st);
                p->next->data = st;
                p->next->next = NULL;
                p = p->next;
            }

            scanf("%d", &st);
            second = (node *)malloc(sizeof(node));
            second->data = st;
            second->next = NULL;
            p = second ;
            for (int i = 1; i < n; i++)
            {
                p->next = (node *)malloc(sizeof(node));
                scanf("%d", &st);
                p->next->data = st;
                p->next->next = NULL;
                p = p->next;
            }
            node * pf = first, * qf = second, * outcome, *ip;
            if (pf->data < qf->data)
                outcome = pf, pf = pf -> next;
            else
                outcome = qf, qf = qf -> next;
            ip = outcome;
            while (pf &&  qf)
            {
                if (pf->data < qf->data)
                {
                    ip->next = pf;
                    pf = pf->next;
                    ip = ip->next;
                }
                else
                {
                    ip->next = qf;
                    qf = qf ->next;
                    ip = ip ->next;
                }
            }
            if (pf)
                ip->next = pf;
            if (qf)
                ip->next = qf;
            ip = outcome;
            while (ip->next)
            {
                printf("%d ", ip->data);
                ip = ip -> next;
            }
            printf("%d\n", ip->data);
        }
    }
    return 0;
}



