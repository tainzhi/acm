class Solution {
public:
    // 先插入身高高的
    // 如果相同身高h的, 按照索引 k 从低到高排列
    // 因为对于身高矮的, 再插入身高矮的, 按照身高矮的索引插入, 那么不会影响已经排好的身高高的
    // 对于身高高的, 看不到身高矮的
    // 思想: 先把身高从高到低排序, 再对索引从低到高排序
    //      遍历, 遇到身高矮的, 则按照其索引插入, 因为已经排好的都是比他高的
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int>b) {
            if (a[0] == b[0]) {
                // 索引从低到高
                return a[1] < b[1];
            } else {
                // height从高到低
                return a[0] > b[0];
            }
        });
        vector<vector<int>> result;
        for (int i = 0; i < people.size(); i++) {
            result.insert(result.begin() + people[i][1], people[i]);
        }
        return result;
    }
};