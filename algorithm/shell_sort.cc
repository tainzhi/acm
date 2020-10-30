#include <iostream>
#include <string>
// 必须包含
#include <vector>

using namespace std;

void shellSort(vector<int> &nums) {
    int h = 1, length = nums.size();
    while ( h < length /3) {
        h = h * 3 + 1;
    }
    while ( h >= 1) {
        for (int i = h; i < length; i++) {
            for (int j = i; (j-h)>=0; j-=h) {
                if (nums[j] < nums[j-h]) {
                    std::swap(nums[j-h], nums[j]);
                }
            }
        }
        h /= 3;
    }
}

int main()  {
    int num;
    vector<int> array  {1, -1, 3, 0, 10, 100, 9, 8, 7, 3};
    // Ctrl+D 结束输入
    // while (cin>>num) {
    //     array.push_back(num);
    // }
    shellSort(array);
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<" ";
    }
    // 输出换行
    cout<<endl;
}
