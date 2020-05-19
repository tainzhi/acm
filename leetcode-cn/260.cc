class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int diff = 0;
        for (int num: nums) { diff ^= num; }
        diff &= (-diff);
        for (int num: nums) { 
            if ((diff & num) == 0) result[0] ^= num;
            else result[1] ^= num;
        }
        return result;
    }
};