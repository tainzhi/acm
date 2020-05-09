class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> smap;
        for (auto c: s) {
            smap[c]++;
        }
        int count = 0;
        for (auto m: smap) {
            count += m.second / 2;
        }
        int n = count * 2;
        return n == s.size() ? n : n + 1;
    }
};