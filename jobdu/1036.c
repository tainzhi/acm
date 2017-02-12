#include <stdio.h>

int Convert(int bits[], int bit_count) {
    int result = 0, pow = 1;
    for (int i = bit_count - 1; i >= 0; --i) {
        result += pow * bits[i];
        pow *= 10;
    }
    return result;
}

int main() {
    int n;
    int bits[5];
    while (scanf("%d", &n) != EOF) {
        scanf("%d %d %d", &bits[1], &bits[2], &bits[3]);
        int max = 0, high_bit, low_bit;
        for (int i = 1; i <= 9; ++i) {
            for (int j = 0; j <= 9; ++j) {
                bits[0] = i;
                bits[4] = j;
                int total = Convert(bits, 5);
                if (total % n == 0) {
                    int price = total / n;
                    if (price > max) {
                        max = price;
                        high_bit = i;
                        low_bit = j;
                    }
                }
            }
        }
        if (max == 0)
            printf("0\n");
        else
            printf("%d %d %d\n", high_bit, low_bit, max);
    }
    return 0;
}

