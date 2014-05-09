/*************************************************************************
    > File:  2204.cc
    > Author:muqing
    > Mail:  qfq0601@gmail.com 
    > CreateTime:   2014-05-09 12:43:52
    > LastModified: 2014-05-09 15:42:39
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

using namespace std;

typedef unsigned long long ull;

vector<int> prime;
ull answer;

bool IsPrime(int n)
{
    for (int i=2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void GetPrime()
{
    for (int i=2; i<60; i++)
        if (IsPrime(i))
            prime.push_back(i);
}

void dfs(int idx, ull num, int k, int condition, ull n)
{
    if (k == 0)
    {
        ull temp = pow(double(n), 1.0 / num);
        answer += temp * ((condition&1) ? 1: -1);
        return;
    }
    if (idx >= prime.size())
        return;
    if (num * prime[idx] < 60)
        dfs(idx+1, num * prime[idx], k-1, condition, n);
    dfs(idx+1, num, k, condition, n);
    return;
}

int main()
{
    ull n;
    GetPrime();
    while (cin>>n)
    {
        answer = 0;
        for (int i=1; i<=3; i++)
            dfs(0, 1, i, i, n);
        printf("%llu\n", answer-1);
    }
    return 0;
}
   



