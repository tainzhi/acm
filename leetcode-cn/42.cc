/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:

// 方法1: 暴力法 列能储水的最大高度
    int trap1(vector<int>& height)
    {
        if (height.size() < 3) return 0;
        int ans = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            int maxLeftH = -1, maxRightH = -1;
            for (int j = 0; j < i; ++j) {
                maxLeftH = max(maxLeftH, height[j]);
            }
            for (int j = i + 1; j < height.size(); ++j) {
                maxRightH = max(maxRightH, height[j]);
            }
            int minH = min(maxLeftH, maxRightH);
            if (minH > height[i]) ans += minH  - height[i];
        }
        return ans;
    }

// 方法2: 动态规划 
// 方法1中每次都要求解最大值, 可以先遍历保留下来
    int trap2(vector<int>& height) {
        if (height.empty()) return 0;
        int n = height.size();
        vector<int> leftMaxH(n, 0), rightMaxH(n, 0);
        leftMaxH[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMaxH[i] = std::max(leftMaxH[i - 1], height[i]);
        }
        rightMaxH[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMaxH[i] = max(rightMaxH[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans += min(leftMaxH[i], rightMaxH[i]) - height[i];
        }
        return ans;
    }

// 方法3: 单调栈
    int trap3(vector<int>& height) {
        stack<int> stk;
        int ans = 0, low = INT_MAX;
        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                // 地面高度
                int low = height[stk.top()];
                stk.pop();
                // 必须有墙
                if (!stk.empty() && height[stk.top()] > low) {
                    // 地面和两堵墙之间能储满的水
                    ans += (min(height[stk.top()], height[i]) - low) * (i - stk.top() - 1);
                }
            }
            stk.push(i);
        }
        return ans;
    }

// 方法4: 双指针法
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans;
        while (left < right) {
            if (height[left] < height[right]){
                if (height[left] > leftMax) leftMax = height[left];
                else {
                    ans += (leftMax - height[left]);
                    ++left;
                }
            } else {
                if (height[right] > rightMax) rightMax = height[right];
                else {
                    ans += (rightMax - height[right]);
                    --right;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

