class Solution {
public:
    bool hasAlternatingBits(int n) {
        int beforeBit = n &1;
        n >>= 1;
        for (int i = 1; i  < 32 && n > 0; i++) {
            if (beforeBit == (n&1)) return false;
            beforeBit = n&1;
            n >>= 1;
        }
        return true;
    }
};