#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000100

long long int numbers[MAX_SIZE];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &numbers[i]);
        }
        long long int sum = 0, max_sum = (-1) * pow(2, 63);
        for (int i = 0; i < n; ++i) {
            if (sum + numbers[i] > numbers[i]) {
                sum = sum + numbers[i];
            } else {
                sum = numbers[i];
            }
            if (sum > max_sum) max_sum = sum;
        }
        printf("%lld\n", max_sum);
    }
    return 0;
}
