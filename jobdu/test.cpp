/*************************************************************************
    > File: 
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Tue 25 Feb 2014 10:34:27 AM CST
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

char *mystrcpy(char *strDest, const char *strSour)
{
    if (strDest == NULL || strSour == NULL)
        throw "Invalid arguments!";
    char *strTemp = strDest;
    while ((*strTemp++ = *strSour++) != '\0');
    return strTemp;
}

int main()
{
    printf("%d\n", 1000000000);
    return 0;
}
