#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define N 1000100

using namespace std;

int GetBitOneRight(int n)
{
    if (n == 0)
        return -1;
    int bit_one = 0;
    while (1)
    {
        if (n % 2 == 1)
            break;
        n >>= 1;
        bit_one++;
        //printf("n=%d bit_one=%d\n", n, bit_one);
    }
    return bit_one;
}

bool IsBitOneSame(int bit_one, int n)
{
    int count = bit_one;
    while (count > 0)
    {
        count--;
        n >>= 1;
    }
    if (n % 2)
        return true;
    else
        return false;
}


int main()
{
    int n, number[N];
    while (scanf("%d", &n) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d", &number[i]);
        int xor_outcome = 0;
        for (int i=0; i<n; i++)
            xor_outcome ^= number[i];
        int xor_bit_one = GetBitOneRight(xor_outcome);
        int one_part = 0, two_part = 0;
        for (int i=0; i<n; i++)
        {
            if (IsBitOneSame(xor_bit_one, number[i]))
                one_part ^= number[i];
            else
                two_part ^= number[i];
        }
        if (one_part > two_part)
            swap(one_part, two_part);
        printf("%d %d\n", one_part, two_part);
    }
    return 0;
}
