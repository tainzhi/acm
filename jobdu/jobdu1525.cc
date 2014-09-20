#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void reverse(char str[], int beg, int end) {
    while (beg < end) {
        str[beg] = str[beg] ^ str[end];
        str[end] = str[beg] ^ str[end];
        str[beg] = str[beg] ^ str[end];
        beg++, end--;
    }
}

int main()
{
    char str[1000100];
    int n;
    while (scanf("%d", &n) != EOF)
    {
        char c;
        scanf("%c", &c);
        if (n == 0)
            break;
        gets(str);
        /*
        printf("*******\n");
        puts(str);
        printf("len =%d*******\n", strlen(str));
        */
        int beg = 0, end = n - 1;
        for (int i=0; i<n; i++)
            if (str[i] != ' ') {
                beg = i;
                break;
            }
        for (int i=n-1; i>=0; i--)
            if (str[i] != ' ') {
                end = i;
                break;
            }
        int point = beg, count = 0;
        for (int i= beg; i<=end; i++) {
            if (str[i] != ' ') {
                count++;
                if (i == end) {
                    reverse(str, point, i);
                    point = point + count -1;
                    break;
                }
                else if ((i+1) <= end  && str[i+1] == ' ') {
                    reverse(str, point, i);
                    point = point + count + 1;
                    count = 0;
                }
            }
        }
        if (beg > 0 && str[beg - 1] == ' ')
            beg--;
        if (end < n - 1 && str[end + 1] == ' ')
            point++;
        for (int i=beg; i<=point; i++)
            putchar(str[i]);
        printf("\n");
    }
    return 0;
}


