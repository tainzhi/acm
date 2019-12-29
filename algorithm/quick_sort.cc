#include <iostream>
#include <string>
// 必须包含
#include <vector>

using namespace std;

void quickSort(vector<int>&nums, int low, int high) {
    if (low >= high) return;
    int i = low, j = high + 1;
    int pivot = nums[i];
    while (true) {
        while (nums[++i] < pivot) {
            if (i == high) break;
        }
        while (nums[--j] > pivot) {
            if (j == low) break;
        }
        if (i >= j) break;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    int temp = nums[low];
    nums[low] = nums[j];
    nums[j] = temp;
    quickSort(nums, low, j-1);
    quickSort(nums, j+1, high);
}

vector<int> quickSort(vector<int> &nums)  {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

int main()  {
    int num;
    vector<int> array;
    // Ctrl+D 结束输入
    while (cin>>num) {
        array.push_back(num);
    }
    quickSort(array);
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<" ";
    }
    // 输出换行
    cout<<endl;
}
