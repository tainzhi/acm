#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
    int n, m;
    while (scanf("%d", &n) != EOF)
    {
        if (n==0)
            break;
        scanf("%d", &m);
        int last = 0;
        for (int i=2; i<=n; i++)
            last = (last + m) % i;
        printf("%d\n", last + 1);
    }
    return 0;
}

