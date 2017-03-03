#include <stdio.h>
#include <string.h>

long long Fi(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * Fi(n - 1);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%lld\n", Fi(n));
    }
    return 0;
}
