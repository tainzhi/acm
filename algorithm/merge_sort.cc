#include <iostream>
#include <string>
// 必须包含
#include <vector>

using namespace std;

void merge(vector<int>&nums, vector<int>&temp_nums, int low, int mid, int high) {
    int pl = low, ph = mid +1, p = low;
    while (pl <= mid && ph <= high) {
        if (nums[pl] <= nums[ph]) {
            temp_nums[p++] = nums[pl++];
        } else {
            temp_nums[p++] = nums[ph++];
        }
    }
    while (pl <= mid) {
        temp_nums[p++] = nums[pl++];
    }
    while (ph <= high) {
        temp_nums[p++] = nums[ph++];
    }
    for (int i = low; i <= high; i++) {
        nums[i] = temp_nums[i];
    }
}

void mergeSort(vector<int>&nums, vector<int>&temp_nums, int low, int high) {
    if (low == high) return;
    int mid = low + ((high - low)>>1);
    mergeSort(nums,temp_nums, low, mid);
    mergeSort(nums,temp_nums, mid+1, high);
    merge(nums, temp_nums, low, mid, high);
}


vector<int> mergeSort(vector<int> &nums)  {
    vector<int> temp_nums = vector<int>(nums.size());
    mergeSort(nums, temp_nums, 0, nums.size() - 1);
    return nums;
}

int main()  {
    int num;
    vector<int> array;
    // Ctrl+D 结束输入
    while (cin>>num) {
        array.push_back(num);
    }
    mergeSort(array);
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<" ";
    }
    // 输出换行
    cout<<endl;
}
