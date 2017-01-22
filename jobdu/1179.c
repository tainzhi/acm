#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long y1 = 0, y2 = 0, multi;
    int tag = 1, i;
    int n;
    while (scanf("%d", &n) != EOF) {
        y1 = 0;
        y2 = 0;
        tag = 1;
        multi = 1;
        for (i = 1; i <= n; i++)
        {
            multi *= i;
            if (tag == 1) {
                tag = 0;
                y1 += multi;
            } else {
                tag = 1;
                y2 += multi;
            }
        }
        printf("%lld %lld\n", y1, y2);
    }
    return 0;
}
