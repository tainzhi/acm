class Solution {
public:
    int numSquares(int n) {
        int visit[n + 1];
        std::fill(visit, visit + n + 1, 0);
        queue<int> q;

        q.push(n);
        visit[n] = 1;
        int level = 0;
        while (!q.empty()) {
            int qs = q.size();
            while (--qs >= 0) {
                int cn = q.front();
                q.pop();
                if (cn == 0) {
                    return level;
                }
                for (int i = 1; i * i <= cn; i++) {
                    if (visit[cn - i * i] == 0) {
                        q.push(cn - i * i);
                        visit[cn - i * i] = 1;
                    }
                }
            }
            level++;
        }
        return level;
    }
};