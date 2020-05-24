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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>b) {
            return a[1] < b[1];
        });
        int ret = 0;
        std::fill_n(boomed, points.size(), false);
        for (int i = 0; i < points.size(); i++){
            if (!boomed[i]) {
                for (int j = i +1; j < points.size(); j++){
                    if (points[j][0] <= points[i][1]) {
                        boomed[j] = true;
                    }
                }
                boomed[i] = true;
                ret++;
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<int>> points;
    points.push_back({10, 16});
    points.push_back({2, 8});
    points.push_back({7, 12});
    points.push_back({1, 6});
    Solution solution ;
    cout<<solution.findMinArrowShots(points)<<endl;
    return 0;
}