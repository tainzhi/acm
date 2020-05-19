class Solution {
public:
    int findComplement(int num) {
        return num ^= (0xffffffff);
    }
};