/*************************************************************************
    > File:  2841.cc
    > Author:muqing
    > Mail:  qfq0601@gmail.com 
    > CreateTime:   2014-05-31 15:21:32
    > LastModified: 2014-05-31 17:37:38
 ************************************************************************/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <iostream>
#define N 100010

using namespace std;

typedef unsigned long long int ull;
ull result;
vector<int> frac[N];
bool tag[N];

void GetOdd()
{
    memset(tag, true, sizeof(tag));
    for (int i=2; i<N; i++)
        if (tag[i])
        {
            frac[i].push_back(i);
            for (int j=i+i; j<N; j += i)
            {
                tag[j] = false;
                frac[j].push_back(i);
            }
        }
}

void dfs(int id, int cnt, int composi, int mi, int n)
{
    if (cnt > 0)
    {
        int temp = n / composi;
        int sig = (cnt & 1) ? 1: -1;
        //printf("%d %d\n", temp, sig);
        result += sig * temp;
        return;
    }
    if (cnt + 1 <= frac[mi].size())
        dfs(id, cnt + 1, frac[mi][id] * composi, mi, n);
    if (id + 1 < frac[mi].size())
        dfs(id+1, cnt, composi, mi, n);
}

int main()
{
    int test;
    GetOdd();
    //for (int i=2; i<10; i++)
        //printf("%d %d\n", i, frac[i].size());
    cin>>test;
    while (test--)
    {
        int m, n;
        ull outcome = 0;
        cin>>m>>n;
        if (m > n)
            swap(m, n);
        if (m == 1)
            outcome = n;
        else
        {
            outcome += n;
            for (int i=2; i<=m; i++)
            {
                result = 0;
                dfs(0, 0 , 1, i, n);
                //printf("%d****\n", result);
                outcome += (n - result);
            }
        }
        cout<<outcome<<endl;
    }
    return 0;
}
