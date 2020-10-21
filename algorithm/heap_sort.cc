#include <iostream>
#include <algorithm>

using namespace std;

void max_heapify(int arr[], int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if ((son + 1) <= end && arr[son+1] > arr[son]) {
            son++;
        }
        if (arr[dad] >= arr[son]) {
            return;
        }
        std::swap(arr[dad], arr[son]);
        dad = son;
        son = dad * 2 + 1;
    }
}

void heap_sort(int arr[], int len) {
    // 构造大根堆, 从第一个非叶子节点开始
    for (int i = len/2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    for (int i = len - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        // 根节点不满足 大根堆属性, 从根节点重构
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int)sizeof(arr) / sizeof(*arr);
    heap_sort(arr, len);
    for (int i = 0; i < len; i++) 
        cout<< arr[i]<< " ";
    cout<<endl;
    return 0;
}
