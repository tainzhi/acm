#include <iostream>
#include <cmath>

using namespace std;

bool judgeSquareSum(int c) {
    unsigned int i = 0, j = (int)(sqrt(c));
    bool result = false;
    while (i <= j) {
        unsigned int sum = i * i + j * j;
        if (sum == c) {
            result = true;
            break;
        } else if (sum < c) {
            i++;
        } else {
            j--;
        }
    }
    return result;
}

    int main() {
    int target;
    while (cin >> target) {
        bool result = judgeSquareSum(target);
            cout<<(result ? 1 : 0)<<endl;
    }
    return 0;
}
