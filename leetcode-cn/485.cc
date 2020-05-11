class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int countOne = 0, maxCount = 0;
        for (auto i: nums) {
            if (i == 1) {
                countOne++;
            } else  {
                maxCount = std::max(countOne, maxCount);
                countOne = 0;
            }
        }
        return std::max(maxCount, countOne);
    }
};