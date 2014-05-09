#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF)
    {
        int outcome = 0;
        while (1)
        {
            outcome = m ^ n;
            m <<= 1, n <<= 1;
            m = m & n;
            if (m == 0)
                break;
            n = outcome;
        }
        printf("%d\n", outcome);
    }
    return 0;
}

