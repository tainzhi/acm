
#include <stdio.h>

int main()
{
    int m, n, i, j, count, flag;
    int matrix[12][12], temp;
    while (scanf("%d", &m))
    {
        if (m == 0)
            break;
        scanf("%d", &n);
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &matrix[i][j]);
        count = 0;
        for (i = 0; i < m; i++)
        {
            flag = 0;
            for (j = 0; j < n; j++)
            {
                scanf("%d", &temp);
                matrix[i][j] += temp;
                if (matrix[i][j] != 0)
                    flag = 1;
            }
            if (flag == 0)
                count++;
        }
        for (j = 0; j < n; j++)
        {
            flag = 0;
            for (i = 0; i < m; i++)
                if (matrix[i][j] != 0)
                    flag = 1;
            if (flag == 0)
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
