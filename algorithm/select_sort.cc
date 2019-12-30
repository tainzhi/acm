#include <iostream>
#include <string>
// 必须包含
#include <vector>

using namespace std;

vector<int> selectSort(vector<int> &nums) {
    int min_index = 0, temp;
    for (int i = 0; i < nums.size(); ++i) {
        min_index = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        std::swap(nums[min_index], nums[i]);
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
    selectSort(array);
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<" ";
    }
    // 输出换行
    cout<<endl;
}
