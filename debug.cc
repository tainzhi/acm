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
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size() + 1;
        int tag[n];
        std::fill_n(tag, 0, n);
        vector<int> result;
        for (auto i: nums) {
            tag[i]++;
            if (tag[i] > 1) {
                result.push_back(i);
            }
        }
        for (int i = 1; i < n; ++i) {
            if (tag[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};