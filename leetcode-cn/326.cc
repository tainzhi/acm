class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n) {
            if (n == 1) return true;
            n /= 3;
        }
        return false;
    }
};