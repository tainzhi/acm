class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long tmpX = x, newX = 0;
        while (tmpX > 0){
            newX = newX * 10 + tmpX % 10;
            tmpX /= 10;
        }
        return newX == x;
    }
};