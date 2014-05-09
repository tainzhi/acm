#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#define N 1000100

int emit[N];

int main()
{
    int n, m;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        scanf("%d", &m);
        if (n == 1)
            printf("1\n");
        else
        {
            for (int i=1; i<=n; i++)
                emit[i] = 0;
            int leave = n, index=1, count = 1, last;
            while (leave > 1)
            {
                while (count <= m)
                {
                    if (emit[index] == 0)
                    {
                        count++;
                        last = index;
                    }
                    index++;
                    if (index > n)
                        index = 1;
                }
                count=1;
                emit[last] = 1;
                leave--;
            }
            for (int i=1; i<= n; i++)
                if (emit[i] == 0)
                    printf("%d\n",i);
        }
    }
    return 0;
}


