class Solution {
public:
    // 暴力法 o(n^3)

    // 扩展中心法: 以字符或者两个字符中间为中心, 分别向两边扩展
    string longestPalindrome2(string s) {
        int start = 0, maxLen= 0;
        for (int i = 0; i < s.size(); i++) {
            // 以char为中心
            int charCenterLen = expandAroundCenter(s, i, i);
            // 以两个相等字符aa的中心为中心
            int twoCharCenterLen = expandAroundCenter(s, i, i + 1);
            int currentLen = std::max(charCenterLen, twoCharCenterLen);
            if (currentLen > maxLen){
                maxLen = currentLen;
                // 以i为中心, 回文串的起始位置先-1在除以2
                start = i - (maxLen - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

    int expandAroundCenter(string s, int start, int end) {
        while (start >= 0 && end < s.size() && s[start] == s[end]) {
            start--;
            end++;
        }
        // start和end要么超出范围, 要么不等
        return end - start - 1;
    }

    // 动态规划 P(i,j)=(P(i+1,j−1)&&S[i]==S[j]), P(i, j)表示i-j之间是否是回文字符串
    // i从高到底, j从低到高而且([j-1] - [i+1] > 0 推出 (j-i))
    string longestPalindrome3(string s) {
        if (s.size() == 0) return "";
        int palindromeStart, palindromeMaxLen = 0;
        int len = s.size();
        bool dp[len][len];
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                // (j -i<=2) 回文初始情况, 要么单一字符j=i, j-i=0; 要么两个字符
                dp[i][j] = s[i] == s[j] && ((j - i) < 2 || dp[i+1][j-1]);
                if (dp[i][j] && ((j - i +1) > palindromeMaxLen)) {
                    palindromeMaxLen = j - i +1;
                    palindromeStart = i;
                }
            }
        }
        return s.substr(palindromeStart, palindromeMaxLen);
    }

    // 动态规划2: 使用一个辅助string.reverse(), dp[i][j] = dp[i-1][j-1] + 1, if s[i] == reverseS[j]
    // 还要确保翻转后的位置对应, 比如`abc1abc`翻转后`cba1cba`不满足要求
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        string reverseS(s);
        std::reverse(reverseS.begin(), reverseS.end());
        int length = s.size();
        int palindromeStart, maxPalindromeLength  = 0, dp[length][length];
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (s[i] == reverseS[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    // 翻转前的位置
                    int beforeStart  = length - 1 - j;
                    if ((maxPalindromeLength < dp[i][j] ) && (i - beforeStart + 1 == dp[i][j])) {
                        maxPalindromeLength = dp[i][j];
                        palindromeStart = i;
                    }
                }
            }

        }
        return s.substr(palindromeStart - maxPalindromeLength +1, maxPalindromeLength);
    }

};