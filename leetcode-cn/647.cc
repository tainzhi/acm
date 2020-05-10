class Solution {
public:
    int countSubstrings1(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            int charCenterLen = palindrome(s, i, i);
            result += (charCenterLen +1) / 2;
            int twoCharCenterLen = palindrome(s, i, i+1);
            result += twoCharCenterLen / 2;
        }
        return result;
    }

    int palindrome(string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return r - l - 1;
    }
};