
#include <iostream>
#include <string>
// 必须包含
#include <vector>

using namespace std;
int binary_search(vector<int> &nums, int low, int high, int value) {
    int mid;
    while (low <= high) {
        // 位操作，除2
        mid = (low + high) >> 1;
        if (nums[mid] < value) {
            // value只可能在mid的右半区域
            low = mid + 1;
        } else {
            // value只可能在mid的左半区域
            high = mid - 1;
        }
    }
    return low;
}

// 二分插入排序，对已经有序的子序列，二分查找找到位置
vector<int> binary_insertSort(vector<int> &nums) {
    int temp, j, location;
    for (int i = 1; i < nums.size(); i++) {
        temp = nums[i];
        location = binary_search(nums, 0, i-1, nums[i]);
        for (j = i; j > location; j--) {
            nums[j] = nums[j-1];
        }
        nums[location] = temp;
    }
    return nums;
}

vector<int> insertSort(vector<int> &nums) {
    int temp, j;
    for (int i = 1; i < nums.size(); i++) {
        temp = nums[i];
        for (j = i; j > 0 && nums[j-1] > temp ; j--) {
            nums[j] = nums[j-1];
        }
        nums[j] = temp;
    }
    return nums;
}

int main()  {
    int num;
    vector<int> array;
    // 回车enter后，Ctrl+D 结束输入
    while (cin>>num) {
        array.push_back(num);
    }
    binary_insertSort(array);
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<" ";
    }
    // 输出换行
    cout<<endl;
}
