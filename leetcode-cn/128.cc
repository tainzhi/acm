/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int num: nums) {
            set.insert(num);
        }
        int maxLen = 0, len;
        for (int num: nums) {
            // 不是最小的起点, 有比num更小的num-1
            // 如果不存在num-1, 那么set.count(num -1) 为0
            if (num != INT_MIN && set.count(num - 1)) {
                continue;
            }
            len = 0;
            // num最小, num+1存在
            while (num != INT_MAX && set.count(num)) {
                len++;
                num++;
            }
            maxLen = std::max(maxLen, len);
        }
        return maxLen;
    }
};
// @lc code=end

