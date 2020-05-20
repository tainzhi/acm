class Solution {
public:
    int findComplement(int num) {
        int rev = 0, tmp = num;
        while (tmp){
            rev <<= 1;
            rev += 1;
            tmp >>= 1;
        };
        return num ^ rev;
    }
};