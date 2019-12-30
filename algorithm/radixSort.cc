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
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int d = 0;
    while (max) {
        d++;
        max /= 10;
    }
    return d;
}    

void radix_sort(int arr[], int n) {
    int d = max_bit(arr, n);
    printf("%d\n", d);
    int *tmp = new int[n];
    int *count = new int[10];
    int radix = 1, k;
    // 排序d趟
    for (int i = 0; i < d; i++) {
        // 桶计数器清零
        for (int j = 0; j < 10; j++) {
            count[j] = 0;
        }
        // 从个位起， 记录每个桶中的个数
        for (int j = 0; j < n; j++) {
            k = (arr[j] / radix) % 10;
            count[k]++;
        }
        for (int j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        // 核心：把每个元素放置到相应的桶中， 桶中对应的元素也有序
        for (int j = n - 1; j >= 0; j--) {
            k = (arr[j] / radix) % 10;
            tmp[--count[k]] = arr[j];
        }
        // 将临时数组的数据copy到原数组
        for (int j = 0; j < n; j++) {
            arr[j] = tmp[j];
        }
        radix *= 10;
    }
    delete []tmp;
    delete []count;
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
