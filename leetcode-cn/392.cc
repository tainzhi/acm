class Solution {
public:
    bool isSubsequence(string s, string t) {
        int is = 0, it = 0;
        while (is < s.length() && it < t.length()) {
            if (s[is] == t[it]) {
                is++;
            }
            it++;
        }
        return is == s.length();
    }
};