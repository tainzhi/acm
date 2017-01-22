#include <stdio.h>

#define MAX_SIZE 105

int main()
{
    int n, i, j;
    int matrix[MAX_SIZE][MAX_SIZE];
    int flag; 
    char yes[] = "Yes!", no[] = "No!";
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &matrix[i][j]);
        flag = 1;
        for (i = 0; i < n; i++)
            for (j = i; j < n; j++)
            {
                /* printf("i j = %d\n", matrix[i][j]); */
                if (matrix[i][j] != matrix[j][i])
                {
                    flag = 0;
                    break;
                }
            }
        if (flag)
            printf("%s\n", yes);
        else
            printf("%s\n", no);
    }
    return 0;
}
