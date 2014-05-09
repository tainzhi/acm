/*************************************************************************
    > File: 
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Tue 25 Feb 2014 11:44:10 AM CST
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
    char str[10];
    while (gets(str))
    {
        int leng = strlen(str);
        sort(str, str+leng);
        puts(str);
        while (next_permutation(str, str+leng))
            puts(str);
    }
    return 0;
}
