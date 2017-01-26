#include <stdio.h>

int GetBitCount(int n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

int Judge(int n, int multi, int count) {
    /* printf("%d %d %d\n", n, multi, count); */
    int lowbit = 0, rad = 1;
    for (int i = 0; i < count; i++) {
        lowbit += (multi % 10) * rad;
        rad *= 10;
        multi /= 10;
    }
    if (lowbit == n)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    char yes[] = "Yes!", no[] = "No!";
    while (scanf("%d", &n) != EOF) {
        int count = GetBitCount(n);
        if (Judge(n, n * n, count))
            printf("%s\n", yes);
        else
            printf("%s\n", no);
    }
    return 0;
}
