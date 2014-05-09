/*************************************************************************
    > File: jobdu 1369
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Tue 25 Feb 2014 10:22:08 AM CST
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

void operate(string str, int begin)
{
    if (begin == str.length() - 1)
    {
        cout<<str<<endl;
        return;
    }
    string stp(str);
    operate(str, begin+1);
    for (int i=begin+1; i < stp.length(); i++)
    {
        //printf("i=%dn", i);
        if (stp[begin] == stp[i])
            continue;
        swap(stp[begin], stp[i]);
        if (begin+1 < i && stp[begin+1] > stp[i])
            swap(stp[begin+1], stp[i]);
        operate(stp, begin+1);
    }
    return;
}

int main()
{
    string str;
    while (cin>>str)
    {
        for (int i=0; i<str.length()-1; i++)
        {
            for (int j=i+1; j<str.length(); j++)
                if (str[j-1] > str[j])
                    swap(str[j-1], str[j]);
        }
        //cout<<"*****"<<str<<endl;
        operate(str, 0);
    }
    return 0;
}
