class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> numMap;
        for (auto c: nums) {
            numMap[c]++;
        }
        for (auto c: nums) {
            if (numMap[c] > 1) {
                return true;
            }
        }
        return false;
    }
};