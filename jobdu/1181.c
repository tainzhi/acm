#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *nums, int n) {
    int temp, i, j;
    for (i = 1; i < n; i++)
    {
        if (nums[i] < nums[i - 1]) {
            temp = nums[i];
            j = i;
            while (j > 0 && (temp < nums[j - 1]))
            {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = temp;
        }
    }
}

void ShellSort(int *nums, int n)
{
    int i, j, d, temp;
    for (d = n/2; d  >= 1; d /= 2) {
        for (i = d; i < n; i ++) {
            if (nums[i] < nums[i - d]) {
                temp = nums[i];
                j = i - d;
                while (j >= 0 && temp < nums[j])
                {
                    nums[j + d] = nums[j];
                    j -= d;
                }
                nums[j + d] = temp;
            }
        }
    }
}

void BubbleSort(int *nums, int n) {
    int temp, i , j;
    for (i = 0; i < n; i++)
        for (j = n - 1; j > i; j--)
        {
            if (nums[j] < nums[j - 1])
            {
                temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
            }
        }
}

int Partision(int *nums, int front, int end) {
    int pivot = nums[front], low = front, high = end;
    while (low < high) {
        /* printf("low=%d, high=%d\n", low, high); */
        while (low < high && pivot <= nums[high])
            high--;
        nums[low] = nums[high];
        while (low < high && pivot >= nums[low])
            low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}


void QuickSort(int *nums, int front, int end) {
    if (front < end) {
        int pivot = Partision(nums, front, end);
        QuickSort(nums, front, pivot - 1);
        QuickSort(nums, pivot + 1, end);
    }
}

void AdjustDown(int *nums, int k, int n) {
    int temp = nums[k], i = 2 * k + 1;
    while (i < n) {
        if (((i + 1) < n) && (nums[i] < nums[i + 1]))
            i++;
        if (nums[i] > temp) {
            nums[k] = nums[i];
            k = i;
            i = 2 * k + 1;
        } else
            break;
    }
    nums[k] = temp;
}

void StackSort(int *nums, int n) {
    int temp;
    for (int i = n/2 - 1; i >= 0; i--)
        AdjustDown(nums, i, n);
    for (int i = n - 1; i >= 1; i--)
    {
        temp = nums[i];
        nums[i] = nums[0];
        nums[0] = temp;
        AdjustDown(nums, 0, i);
    }
}


void SelectSort(int *nums, int n) {
    int i, j, min, p;
    for (i = 0; i < n; i++)
    {
        p = i;
        min = nums[i];
        for (j = i + 1; j < n; j++)
            if (nums[j] < min)
            {
                min = nums[j];
                p = j;
            }
        if (p != i)
        {
            nums[p] = nums[i];
            nums[i] = min;
        }
    }
}

void Merge(int *nums, int *tnum, int low, int mid, int high) {
    int i, j, k;
    for (i = low; i <= high; i++)
        tnum[i] = nums[i];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high) {
        if (tnum[i] < tnum[j])
            nums[k++] = tnum[i++];
        else
            nums[k++] = tnum[j++];
    }
    while (i <= mid)
        nums[k++] = tnum[i++];
    while (j <= high)
        nums[k++] = tnum[j++];
}

void MergeSort(int *nums, int *tnum, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(nums, tnum, low, mid);
        MergeSort(nums, tnum, mid + 1, high);
        Merge(nums, tnum, low, mid, high);
    }
}

int main()
{
    int n, i;
    int nums[1010];
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%d", nums + i);
        /* InsertSort(nums, n); */
        /* ShellSort(nums, n); */
        /* QuickSort(nums, 0, n - 1); */
        /* StackSort(nums, n); */
        int *tnum = (int *)malloc(sizeof(int) * n);
        MergeSort(nums, tnum, 0, n - 1);
        for (i = 0; i < 1; i++)
            printf("%d", *(nums + i));
        free(tnum);
        for ( ; i < n; i++)
            printf(" %d", nums[i]);
        printf("\n");
    }
}
