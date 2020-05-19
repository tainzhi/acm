class Solution {
public:
    bool isPowerOfTwo2(int n) {
        if (n <= 0) return false;
        while ((n &1) == 0) {
            n /= 2;
        }
        return n == 1;
    }
    
    // 2的幂, 只有一个二进制位 1
    bool isPowerOfTwo1(int n) {
        if (n <= 0) return false;

        return (n & (n-1)) == 0;
    }

    // n &(-n)获取最右边的一个1
    // 2的幂, 只有1个1
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (-n)) == n;
    }
};