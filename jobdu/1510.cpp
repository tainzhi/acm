/*************************************************************************
    > File: jobdu1510.cpp
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Tue 18 Feb 2014 10:35:53 AM CST
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
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            cout<<"%20";
        else
            cout<<str[i];
    }
    cout<<endl;
    return 0;
}

