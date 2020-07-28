/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution1(CustomFunction& customfunction, int z) {
        vector<vector<int>> ret;
        for (int x = 1; x <= 1000; x++) {
            for (int y = 1; y <= 1000; y++) {
                if (customfunction.f(x, y) == z) {
                    ret.push_back(vector<int>{x, y});
                }
            }
        }        
        return ret;
    }

    vector<vector<int>> findSolution2(CustomFunction& customfunction, int z) {
        vector<vector<int>> ret;
        int l, h, mid, t;
        for (int x = 1; x <= 1000; x++) {
            l = 1;
            h = 1000;
            while (l <= h) {
                mid = l + (h - l) / 2;
                t = customfunction.f(x, mid);
                if (t == z) {
                    ret.push_back(vector<int>{x, mid});
                    break;
                } else if (t < z) {
                    l = mid +1;
                } else {
                    h = mid -1;
                }
            }
            if (customfunction.f(x, 1) > z) {
                break;
            }
        }        
        return ret;
    }

    // 双指针法, 根据函数f的偏导递增特性
    // 当outcome小, 只能增加x, 而y是从大到小递减的, 在y比较大的情况已经做了处理
    // 当outcome大, 只能减小y, 若增加y将会变的更大; 若增加x也会变大; 而x比较小的情况已经做了处理
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ret;
        int x = 1, y = 1000, outcome;
        while (x <= 1000 && y >= 1) {
            outcome = customfunction.f(x, y);
            if (outcome == z) {
                ret.push_back(vector<int>{x, y});
                x++;
                y--;
            } else if (outcome < z) {
                x++;
            } else if (outcome > z) {
                y--;
            }
        }
        return ret;
    }
};