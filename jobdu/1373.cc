#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int PowerBase10(int exp)
{
    int outcome = 1;
    for (int i=0; i<exp; i++)
        outcome *= 10;
    return outcome;
}

int GetOccruenceOf1(const char string_number[])
{
    if (*string_number <= '0' || *string_number > '9' || *string_number == '\0')
        return 0;
    int length = strlen(string_number);
    if (length == 1)
        return 1;
    int first = *string_number - '0';
    int occruence_part1;
    if (first > 1)
        occruence_part1 = PowerBase10(length - 1);
    else
        occruence_part1 = atoi(string_number+1) + 1;
    int occruence_part2 = first * (length -1) * PowerBase10(length - 2);
    int occruence_part3 = GetOccruenceOf1(string_number + 1);
    return occruence_part1 + occruence_part2 + occruence_part3;
}

int OccurenceOf1(int n)
{
    if (n <= 0)
        return 0;
    char string_number[20];
    sprintf(string_number, "%d", n);
    //printf("string_number = %s\n", string_number);
    return GetOccruenceOf1(string_number);
}

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        if (a > b)
            swap(a, b);
        printf("%d\n", OccurenceOf1(b) - OccurenceOf1(a-1));
    }
    return 0;
}
