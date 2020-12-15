/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 * 环形排列 是单列排列的加强版
 * 该问题分解成: 要么抢劫[0, n-1)不抢劫第0屋子, 要么抢劫[1, n-2)不抢劫最后一个屋子
 * 对于
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        return std::max(robRooms(nums, 0, nums.size() - 2), robRooms(nums, 1, nums.size() - 1));
    }

    int robRooms(vector<int>& nums, int first, int last) {
        int pre2 = 0, pre1 = 0;
        for(int i = first; i <= last; i++) {
            int cur = std::max(pre1, pre2 + nums[i]);
            pre2 = pre1;
            pre1 = cur;
        }
        return std::max(pre1, pre2);
    }
};
// @lc code=end

