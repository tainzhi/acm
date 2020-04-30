class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> dist(T.size(), 0);
        stack<int> sta;
        for (int i = 0; i < T.size(); i++) {
            while (!sta.empty() && (T[i] > T[sta.top()])) {
                auto t = sta.top();
                sta.pop();
                dist[t] = i - t;
            }
            sta.push(i);
        }
        return dist;
    }
};