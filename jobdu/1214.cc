#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

bool IsUglgNumber(int number)
{
    if (number < 1)
        return false;
    while (number % 2 == 0)
        number /= 2;
    while (number % 3 == 0)
        number /= 3;
    while (number % 5 == 0)
        number /= 5;
    if (number == 1)
        return true;
    else 
        return false;
}

int GetUglyNumber(int index)
{
    int index_count = 0, number = 1, outcome;
    while (1)
    {
        if (IsUglgNumber(number))
        {
            index_count++;
            if (index_count == index)
            {
                outcome = number;
                break;
            }
        }
        number++;
    }
    return outcome;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", GetUglyNumber(n));
    }
    return 0;

