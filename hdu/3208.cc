/*************************************************************************
    > File:  3208.cc
    > Author:muqing
    > Mail:  qfq0601@gmail.com 
    > CreateTime:   2014-05-19 20:06:02
    > LastModified: 2014-05-19 21:42:26
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

#define INF 1e-8
using namespace std;

typedef unsigned long long ull;
vector<int> prime;
ull sum, non_one;
ull a, b;
int record[3];

bool IsPrime(int n)
{
    for (int i=2; i<=sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void dfs(int i, int id, int con, int left, int last)
{
    if (left == 0)
    {
        ull much = (ull)((pow((double)(b + INF), 1.0/con)) + INF) - (ull)(pow((double)(a-1), 1.0/con));
        //printf("big small %lld %lld\n", (ull)(pow((double)b, 1.0/con)), (ull)(pow((double)(a-1), 1.0/con)));
        //printf("con = %d last = %d much =%d\n", con, last, much);
        int sig = (i&1)?1:-1;
        non_one += sig * much;
        sum += sig * much * last;
        return;
    }
    if (id >= prime.size())
        return;
    if (con > b or last > b or prime[id] > b)
        return;
    if (con * prime[id] < 64)
        dfs(i, id+1, con * prime[id], left - 1, prime[id]);
    dfs(i, id + 1, con, left, last);
}

void GetPrime()
{
    for (int i=2; i<64; i++)
        if (IsPrime(i))
            prime.push_back(i);
}

int main()
{
    GetPrime();
    //for (int i=0; i<prime.size(); i++)
        //printf("%d ", prime[i]);
    while (cin>>a>>b)
    {
        if (a == 0 && b == 0)
            break;
        if (a > b)
            swap(a, b);
        sum = non_one = 0;
        for (int i=1; i<=3; i++)
            dfs(i, 0, 1, i, 1);
        //printf("non_one:%d\n", non_one);
        cout<<sum + (b - a + 1 - non_one)<<endl;
    }
    return 0;
}

