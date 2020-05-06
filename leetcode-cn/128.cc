class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (auto i: nums) {
            numSet.insert(i);
        }
        int maxLen = 0, len, j;
        for (auto i: nums) {
            // 不是最小的数
            if (numSet.count(i - 1) && i != INT_MIN) {
                continue;
            }
            len = 1;
            while (i != INT_MAX numSet.count(++i)) {
                len++;
            }
            maxLen = std::max(maxLen, len);
        }
        return maxLen;;
    }
};