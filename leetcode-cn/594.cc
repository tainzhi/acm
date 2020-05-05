class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> numsMap;
        for (auto n: nums) {
            numsMap[n]++;
        }
        int maxLen = 0;
        int len;
        for (auto n: nums) {
            if (numsMap[n-1] == 0 && numsMap[n + 1] == 0) {
                continue;
            } else {
            len = std::max(numsMap[n] + numsMap[n + 1], numsMap[n] + numsMap[n-1]);
            maxLen = std::max(maxLen, len);
            }
        }
        return maxLen;
    }
};