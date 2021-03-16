#include <iostream>
#include <string>
// 必须包含
#include <vector>

using namespace std;

void quickSort(vector<int> &nums, int start, int end)
{
    if (start >= end) return;
    int anchor = start;
    int i = start + 1, j = end;
    while (i < j) {
        while (nums[++i] < nums[anchor])
        {
            if (i >= j || i >= end) break;
        }
        while (nums[--j] > nums[anchor])
        {
            if (i >= j || j <= start) break;
        }
        if (i >= j) break;
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[anchor], nums[i]);
    quickSort(nums, start, i - 1);
    quickSort(nums, i + 1, end);
}

vector<int> quickSort(vector<int> &nums)  {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
}

int main()  {
    int num;
    vector<int> array = {-1, -1, -2, 8, 100, -100, -50, 50, 10, -9};
    // Ctrl+D 结束输入
    // while (cin>>num) {
    //     array.push_back(num);
    // }
    quickSort(array);
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<" ";
    }
    // 输出换行
    cout<<endl;
}
