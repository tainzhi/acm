#include <stdio.h>

#define MAX_SIZE 1000010

int last[MAX_SIZE], new_value[MAX_SIZE];

void Yang(int d) {
    if (d == 1) {
        printf("1 1\n");
        last[1] = 1;
        last[2] = 1;
    } else {
        Yang(d - 1);
        printf("1 ");
        new_value[1] = 1;
        for (int i = 2; i <= d ; i++) {
            new_value[i] = last[i] + last[i-1];
            printf("%d ", new_value[i]);
        }
        printf("1\n");
        new_value[d + 1] = 1;
        for (int i = 1; i <= (d + 1); i++) last[i] = new_value[i];
    }
}
            
int main()  {
    int n;
    while (scanf("%d", &n) != EOF) {
        Yang(n - 1);
    }
    return 0;
}
