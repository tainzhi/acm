#include <iostream>
#include <string>
// 必须包含
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int> &nums) {
    int swap;
    for (vector<int>::size_type ix = 0; ix < nums.size(); ++ix) {
        // 是否需要交换，0：不需要， 1：需要
        // 如果不需要交换，即已经是升序
        swap = 0;
        // 注意不要越界，nums[iy] and nums[iy+1]
        for (vector<int>::size_type iy = 0; iy  < nums.size() - ix - 1; ++iy)
            if (nums[iy] > nums[iy +1]) {
                int temp = nums[iy];
                nums[iy] = nums[iy + 1];
                nums[iy + 1] = temp;
                swap = 1;
            }
        if (swap == 0) {
            break;
        }
    }
    return nums;
}

int main()  {
    int num;
    vector<int> array;
    // Ctrl+D 结束输入
    while (cin>>num) {
        array.push_back(num);
    }
    bubbleSort(array);
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<" ";
    }
    // 输出换行
    cout<<endl;
}
