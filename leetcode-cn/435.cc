class Solution {
public:
    // 贪心算法: 尽可能已经取的区间最大, 丢弃的区间最少
    // 有三种情况: 
    // 情况1: 如果当前区间与已经取的区间不重叠, 那么把当前区间加入
    // 情况2: 有重叠, 当前区间在存在的区间的右边, 丢弃上个区间, 取当前区间, 可以使得区间更小, 同时丢弃同样的区间数目
    // 情况3: 有重叠, 当前区重叠, 右端点重叠, 那么丢弃该区间
    int eraseOverlapIntervals1(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int> &b) {
            return a[0] < b[0];
            // if (a[0] == b[0]) {
            //     return a[1] < b[1];
            // } else {
            //     return a[0] < b[0];
            // }
        });
        // 取第一个区间
        int pre = 0, discard = 0;
        for (int i = 1; i < intervals.size(); i++) {
            // 当前区间与已经存在的区间不重叠, 取该区间 
            if (intervals[i][0] >= intervals[pre][1]) {
                pre = i;
            } else {
                // 有重叠, 丢弃
                if (intervals[i][1] >= intervals[pre][1]) {
                    // 丢弃当前区间
                    discard++;
                } else {
                    // 丢弃上一个区间, 
                    // 取当前区间, 因为更小
                    pre = i;
                    discard++;
                }
            }
        }
        return discard;
    }

    // 动态规划
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        // 取当前区间后, 能使用的区间最大数目
        // dp[i+1] = max(dp[j]) +1,   { 0 <= j <= i }, 而且i+1区间不能与之前的区间有重叠
        vector<int> dp(intervals.size());
        // 最大的使用区间数目
        int maxUse = 1;
        dp[0] = 1;
        for (int i = 1; i < intervals.size(); i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                if (!isOverlapping(intervals[j], intervals[i]))
                    dp[i] = std::max(dp[j] + 1, dp[i]);
            }
            maxUse = std::max(maxUse, dp[i]);
        }
        return intervals.size() - maxUse;
    }

    bool isOverlapping(vector<int> &a, vector<int> &b) {
        return a[1] > b[0];
    }
};