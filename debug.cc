#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <exception>
#include <map>
#include <list>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> nmap;
        map<int, int> left;
        map<int, int> right;
        vector<int> maxCountNums;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = nums[i];
            // 为了区分left[cnt] = i为0 与map初始化为0, 把所有的位置+1 
            if (left[cnt] == 0) left[cnt] = i +1;
            right[cnt] = i +1;
            nmap[cnt]++;
            if (nmap[cnt] >= maxCount) {
                if (nmap[cnt] > maxCount) {
                    maxCountNums.clear();
                }
                maxCount = nmap[cnt];
                maxCountNums.push_back(cnt);
            }
        }
        int minLength = INT_MAX;
        for (auto num: maxCountNums) {
            minLength = std::min(minLength, right[num] - left[num] + 1);
        }
        return minLength;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findShortestSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}