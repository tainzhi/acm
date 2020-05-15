class Solution {
public:
    // 构造法
    // v[0] = 1, v[1] = 1 + k, v[2] = v[1] - (k-1]), v[3] = v[2] + (k-2)...
    vector<int> constructArray(int n, int k) {
        vector<int> result(n);
        int i, interval;
        result[0] = 1;
        for (i = 1, interval = k; i <= k; i++, interval--) {
            result[i] = (i % 2 == 1) ? (result[i - 1] + interval) : (result[i - 1] - interval);
        }
        for (i = k+1; i < n; i++) {
            result[i] = i + 1;
        }
        return result;
    }

    // 递归
    // 若n=8初始状态
    // 1 2 3 4 5 6 7 8
    // k=1~~~~~~~~         | 1 2 3 4 5 6 7 8 (不翻转，直接返回)
    // k=2~~~~~~~~         1 | 8 7 6 5 4 3 2
    // k=3~~~~~~~~         1 8 | 2 3 4 5 6 7
    // k=4~~~~~~~~         1 8 2 | 7 6 5 4 3
    // 总结规律：当k>1时,需要翻转的次数为k-1次，每次翻转保留前m(m = 1,2,3...k-1)个数，每次翻转都在原数组进行。
    vector<int> constructArray1(int n, int k) {
        vector<int> v(n);
        for (int i = 1; i <= n; i++) {
            v[i-1] = i;
        }
        for (int i = 1; i < k; i++) {
            reverse(v, i, n - 1);
        }
        return v;
    }

    void reverse(vector<int> &v, int l, int r) {
        while (l < r) {
            std::swap(v[l], v[r]);
            l++;
            r--;
        }
    }
};