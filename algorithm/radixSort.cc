#include <iostream>
#include <string>
#include <ctime>

void print_arr(int * arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max_bit(int arr[], int n) {
    int maxBit = 0;
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0, c = arr[i];
        while (c != 0) {
            cnt++;
            c /= 10;
        }
        maxBit = std::max(maxBit, cnt);
    }
    return maxBit;
}    

void radix_sort(int arr[], int n) {
    int * temp = (int *)malloc(sizeof(int) * n);
    int maxBit = max_bit(arr, n);
    int radix = 1;
    int bulk[10];
    for (int i = 0; i < maxBit; ++i) {
        memset(bulk, 0, sizeof(bulk));
        for (int j = 0; j < n; j++) {
            bulk[arr[j]/radix % 10]++;
        }
        for (int j = 1; j < 10; j++) {
            bulk[j] += bulk[j - 1];
        }
        for (int j = n -1; j >= 0; --j) {
            temp[--bulk[arr[j]/radix % 10]] = arr[j];
        }
        std::copy(temp, temp+n, arr);
        radix *= 10;
    }
    free(temp);
}

int main() {
    int n = 15;
    int * arr = (int *)malloc(sizeof(int) * n);
    srand(time(0));
    // 随机生成0-1000之间的15个数
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
    print_arr(arr, n);
    radix_sort(arr, n);
    print_arr(arr, n);

    free(arr);
    return 0;
}
