#include <iostream>
#include <string>
#include <ctime>

static int max_num = 100;

void print_arr(int * arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void counting_sort(int * arr, int * sorted_arr, int n) {
    int * count_arr = (int *) malloc(sizeof(int) * max_num);
    // 初始计数为0
    for (int i = 0; i < max_num; i++) {
        count_arr[i] = 0;
    }
    // arr[i]有多少个
    for (int i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }
    // arr[i]所在的排好序之后的序列位置一定在之前拍好的arr[i-1]前面
    // 加入小于8的数字有10个，那么8的位置一定从11开始的
    for (int i = 1; i < max_num; i++) {
        count_arr[i] += count_arr[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        sorted_arr[--count_arr[arr[i]]] = arr[i];
    }
    free(count_arr);
}

int main() {
    int n = 10;
    int * arr = (int *)malloc(sizeof(int) * n);
    int * sorted_arr = (int *)malloc(sizeof(int) * n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_num;
    }
    print_arr(arr, n);
    counting_sort(arr, sorted_arr, n);
    print_arr(sorted_arr, n);

    free(arr);
    free(sorted_arr);
    return 0;
}
