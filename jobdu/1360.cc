#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define DiceCount 10
#define DiceMaxPoint 8

long long dynamic_programe[DiceCount+1][DiceCount *DiceMaxPoint+1];

void GetMax(int &one_max, int &two_max, int &three_max, int n, int m)
{
    long long int max_count = -1;
    for (int i=n; i<=n*m; i++)
        if (max_count < dynamic_programe[n][i])
        {
            max_count = dynamic_programe[n][i];
            one_max = i;
        }
    max_count = -1;
    for (int i=n; i<=n*m; i++)
        if (max_count < dynamic_programe[n][i] && i != one_max)
        {
            max_count = dynamic_programe[n][i];
            two_max = i;
        }
    max_count = -1;
    for (int i=n; i<=n*m; i++)
        if (max_count < dynamic_programe[n][i] && i != one_max && i != two_max)
        {
            max_count = dynamic_programe[n][i];
            three_max = i;
        }
}
      
int main()
{
    int n, m;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        scanf("%d", &m);
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n*m; j++)
                dynamic_programe[i][j] = 0;
        /*
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n*m; j++)
                printf("%lld ", dynamic_programe[i][j]);
            printf("\n");
        }
        */
        for (int i=1; i<=m; i++)
            dynamic_programe[1][i] = 1;
        for (int i=2; i<=n; i++)
        {
            for (int j=1*i; j<= m*i; j++)
            {
                for (int k=1; k<=m; k++)
                {
                    if (j-k>=i-1 && dynamic_programe[i-1][j-k] != (long long)0)
                        dynamic_programe[i][j] += dynamic_programe[i-1][j-k];
                }
                //printf("d[%d][%d]=%lld\n",i, j, dynamic_programe[i][j]);

            }
        }
        /*
        for (int i=1; i<=n; i++)
        {
            for (int j=i; j<=i*m; j++)
                printf("%lld ", dynamic_programe[i][j]);
            printf("\n");
        }
        */
        long long kind = (long long)pow(m, n);
        int one_max, two_max, three_max;
        GetMax(one_max, two_max, three_max, n, m);
        for (int i=n; i<=n*m; i++)
            printf("%lld ", dynamic_programe[n][i]);
        printf("%d %.2lf\n", one_max, (double)(dynamic_programe[n][one_max]) / (double)kind);
        printf("%d %.2lf\n", two_max, (double)(dynamic_programe[n][two_max]) / kind);
        printf("%d %.2lf\n", three_max, (double)(dynamic_programe[n][three_max]) / kind);
        printf("\n");
    }
    return 0;
}
