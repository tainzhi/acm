#include <iostream>
#include <vector>

using namespace std;


vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> result;
    int left = 0, right = numbers.size() - 1;
    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            // +1 是因为题目中给的数据从1开始计数
            result.push_back(left + 1);
            result.push_back(right + 1);
            break;
        } else if (numbers[left] + numbers[right] < target) {
            left++;
        } else {
            right--;
        }
    }
    return result;
}

int main() {
    vector<int> array;
    int num;

    while (cin>>num) {
        array.push_back(num);
    }
    vector<int> result = twoSum(array, 10);
    cout<<result[0]<<" "<<result[1]<<endl;

}
