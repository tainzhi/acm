#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

const int BUCKET_NUM = 5;

struct ListNode {
    explicit ListNode(int i = 0): mData(i) {}
    ListNode * mNext;
    int mData;
};

ListNode *  insert(ListNode * head, int val) {
    ListNode dummy, *pre, *cur;
    ListNode * newNode = new ListNode(val);
    dummy.mNext = head;
    pre = &dummy;
    cur = head;
    while (NULL != cur && cur->mData <= val) {
        pre = pre->mNext;
        cur = cur->mNext;
    }
    pre->mNext = newNode;
    newNode -> mNext = cur;
    return dummy.mNext;
}

ListNode * merge(ListNode * left, ListNode * right) {
    ListNode dummy, *pl, *pr, *head = &dummy;
    while (NULL != left && NULL != right) {
        if (left->mData < right->mData) {
            head->mNext = left;
            left = left->mNext;
        } else {
            head->mNext = right;
            right = right->mNext;
        }
        head = head->mNext;
    }
    // 只可能有一个为空， 不可能两个都不为空
    if (NULL != left) head->mNext = left;
    if (NULL != right) head->mNext = right;
    return dummy.mNext;
}

void bucket_sort(int arr[], int n) {
    vector<ListNode *> buckets(BUCKET_NUM, (ListNode *)0);
    for (int i = 0; i < n; i++) {
        int k = arr[i] % BUCKET_NUM;
        buckets[k] = insert(buckets[k], arr[i]);
    }
    ListNode * head = buckets[0];
    for (int i = 1; i < BUCKET_NUM; i++) {
        head = merge(head, buckets[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = head->mData;
        head = head->mNext;
    }
}

void print_arr(int * arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 15;
    int * arr = (int *)malloc(sizeof(int) * n);
    srand(time(0));
    // 随机生成0-1000之间的15个数
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    print_arr(arr, n);
    bucket_sort(arr, n);
    print_arr(arr, n);

    free(arr);
    return 0;
}
