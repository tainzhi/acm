class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int diff = 0;
        // 找到两个不同的数异或的结果
        for (int num: nums) { diff ^= num; }
        // diff最右边的1, 区分出两个不同的数
        diff &= (-diff);
        for (int num: nums) { 
            // 注意: diff & num == 0是错误的写法, ==比&优先级高
            if ((diff & num) == 0) result[0] ^= num;
            else result[1] ^= num;
        }
        return result;
    }
};