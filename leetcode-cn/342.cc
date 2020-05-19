class Solution {
public:
    // 暴力+预预算
    // 输入的整数是 32 位整数 x \le 2^{31} - 1x≤2 
    // 可能的数为4^0 ... 4^15, 一共16中结果
    bool isPowerOfFour(int num) {
        int targetNums[16];
        int d4 = 1;
        targetNums[0] = 1;
        for (int i = 1; i <= 15; i++) {
            d4 *= 4;
            targetNums[i] = d4;
        }
        for (int i = 0; i <16; i++) {
            if (targetNums[i] == num) return true;
        }
        return false;
    }

    // log(4^n) == log(num)
    bool isPowerOfFour1(int num){
        if (num <= 0) {
            return false;
        }
        int n = log(num)/log(4);
        return n * log(4) == log(num);
    }
};