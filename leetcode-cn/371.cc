class Solution {
public:
    // a & b进位,  a^b非进位相加结果
    int getSum(int a, int b) {
        // 进位为0, 那么非进位相加即为结果
        if ((a&b) == 0) return a ^ b;
        // unsigned int防止有符号数溢出
        return getSum(a ^ b, ((unsigned int)(a & b) << 1));
    }
};