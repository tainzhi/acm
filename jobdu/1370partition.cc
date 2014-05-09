/*************************************************************************
    > File: jobdu
    > Author: muqing
    > Mail: qfq0601@gmail.com 
    > Created Time: Thu 27 Feb 2014 08:40:19 AM CST
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
#include <ctime>

using namespace std;

void Partition(int number[], int left, int right, int mid)
{
    //printf("%d %d %d---------\n", left,right, mid);
    int random_at = left+((rand()%(right-left+1)));
    int pivot_key = number[random_at];
    number[random_at] = number[left];
    number[left] = pivot_key;
    int low = left, high = right;
    while (low <= high)
    {
        if (number[low] <= pivot_key)
            low++;
        else
        {
            swap(number[low], number[high]);
            high--;
        }
    }
    number[left] = number[high];
    number[high] = pivot_key;
    if (mid == high)
        return;
    else if (mid>high)
        Partition(number, high+1, right, mid);
    else
        Partition(number, left, high-1, mid);
}

int main()
{
    int number[100000];
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d", &number[i]);
        srand(time(NULL));
        Partition(number, 0, n-1, n/2);
        int most_number = number[n/2];
        int count_most_number = 0;
        for (int i=0; i<n; i++)
            if (most_number == number[i])
                count_most_number++;
        if (count_most_number*2 > n)
            printf("%d\n", most_number);
        else
            printf("-1\n");
    }
    return 0;
}

