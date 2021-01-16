/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        int head = 0, tail = s.size() - 1;
        string vowel = "aoeiuvAOEIVU";
        while (head < tail)
        {
            if (isVowel(s[head]) && isVowel(s[tail]))
            {
                std::swap(s[head], s[tail]);
                head++;
                tail--;
            }
            else if (!isVowel(s[head]))
            {
                head++;
            }
            else if (!isVowel(s[tail]))
            {
                tail--;
            }
        }
        return s;
    }

    bool isVowel(char c) {
        // v, V不是元音字母
        string vowel = "aoeiuAOEIU";
        return vowel.find(c) != vowel.npos;
    }
};
// @lc code=end
