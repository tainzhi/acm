class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        std::sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>b) {
            return a[1] < b[1];
        });
        int ret = 1;
        int end = points[0][1];
        // 贪心: 从最右边缘开始爆破
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                ret++;
                end = points[i][1];
            }
        }
        return ret;
    }
};