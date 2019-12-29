#include <iostream>
#include <string>
// 必须包含
#include <vector>

using namespace std;

vector<int> shellSort(vector<int> &nums) {
    int h = 1, length = nums.size();
    while (h < length /3) {
        h = 3 * h +1;
    }
    while (h >= 1) {
        for (int i = h; i < length; i++) {
            for (int j = i; j >= h && nums[j] < nums[j - h]; j -= h) {
                std::swap(nums[j], nums[j - h]);
            }
        }
        h /= 3;
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
    shellSort(array);
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<" ";
    }
    // 输出换行
    cout<<endl;
}
