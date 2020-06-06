class Solution {
public:
    // 二分法
    int mySqrt1(int x) {
        int low = 1, high = x, mid, sqrt;
        while (low <= high) {
            // (low + high) / 2 容易超过int范围
            mid = low  + (high - low) / 2;
            sqrt = x / mid;
            if (sqrt == mid) {
                return mid;
            } else if (sqrt < mid) {
                // mid 太大
                high = mid - 1;
            } else {
                // mid太小
                low = mid + 1;
            }
        }
        // 跳出时, low > high, 选择尽量小的数字, 比如2.83, 选2
        return high;
    }

    // 牛顿迭代法
    int mySqrt(int x) {
        if ( x == 0) return 0;
        double x0 = x, x1, C = x;
        while (true) {
            x1 = 0.5 * (x0 + C/ x0) ;
            if (fabs(x1 - x0) < 1e-7) {
                break;
            }
            x0 = x1;
        }
        return int(x0);
    }
    
};