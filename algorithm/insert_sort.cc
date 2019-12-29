
#include <iostream>
#include <string>
// 必须包含
#include <vector>

using namespace std;

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
    insertSort(array);
    for (int i = 0; i < array.size(); i++) {
        cout<<array[i]<<" ";
    }
    // 输出换行
    cout<<endl;
}
