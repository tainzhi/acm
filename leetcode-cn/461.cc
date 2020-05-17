class Solution {
public:
    int hammingDistance(int x, int y) {
        int xy = x ^ y;
        int oneCnt = 0;
        while (xy) {
            if (xy & 1) oneCnt++;
            xy >>= 1;
        }
        return oneCnt;
    }
};