class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.empty()) return 0;
        int group[s.size()];
        int t = 0;
        group[t] = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == s[i]){
                group[t] ++;
            } else {
                group[++t] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= t; i++){
            ans += std::min(group[i - 1], group[i]);
        }
        return ans;
    }

};