/*
 * 暴力法o(n^3)复杂度太高, 可以优化
 * 优化思路: 第2层遍历获取 b 时, c = -(a + b)是确定的, 所以没必要再一层循环, 故退化成 o(n^2)复杂度
 * 第一次遍历获取a后, 再从a之后的数中取出 (b+c) = -a
 * 用双指针法. 对已经排好序的数组, 很容易实现
 * 
 * 注意: 去重
 * 1. 对于相同的a去重
 * 2. 对于相同的b or c 去重
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            int end = nums.size() - 1;
            int start = i + 1, target = -nums[i];
            int beforeStart = INT_MIN, beforeEnd = INT_MIN;
            while (start < end) {
                int cur = nums[start] + nums[end];
                if (cur > target) {
                    --end;
                } else if (cur < target) {
                    ++start;
                } else {
                    if (nums[start] != beforeStart || nums[end] != beforeEnd) {
                        beforeStart = nums[start];
                        beforeEnd = nums[end];
                        ans.push_back({nums[i], nums[start], nums[end]});
                    }
                    ++start;
                    --end;
                }
            }
        }
        return ans;

    }
};
// @lc code=end

