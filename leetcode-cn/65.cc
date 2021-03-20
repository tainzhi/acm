/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    enum State {
        STATE_INTIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        // 有整数小数点
        STATE_POINT,
        // 无整数小数点
        STATE_POINT_WITHOUT_INT,
        // 小数
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END,
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_EXP,
        CHAR_ILLEGAL,
    };

    CharType toCharType(char &c) {
        if (c >= '0' && c <= '9') return CHAR_NUMBER;
        if (c == '.') return CHAR_POINT;
        if (c == '-' || c == '+') return CHAR_SIGN;
        if (c == 'e' || c == 'E') return CHAR_EXP;
        return CHAR_ILLEGAL;
    }
    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {STATE_INTIAL, {
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_SIGN, STATE_INT_SIGN},
                {CHAR_POINT, STATE_POINT_WITHOUT_INT},}
            },
            {STATE_INT_SIGN, {
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT_WITHOUT_INT},}
            },
            {STATE_INTEGER, {
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_FRACTION},
                {CHAR_EXP, STATE_EXP},}
            },
            {STATE_POINT, {
                {CHAR_NUMBER, STATE_FRACTION},
                {CHAR_EXP, STATE_EXP},}
            },
            {STATE_POINT_WITHOUT_INT, {
                {CHAR_NUMBER, STATE_FRACTION},}
            },
            {STATE_FRACTION, {
                {CHAR_NUMBER, STATE_FRACTION},
                {CHAR_EXP, STATE_EXP},}
            },
            {STATE_EXP, {
                {CHAR_SIGN, STATE_EXP_SIGN},
                {CHAR_NUMBER, STATE_EXP_NUMBER},}
            },
            {STATE_EXP_SIGN, {
                {CHAR_NUMBER, STATE_EXP_NUMBER},}
            },
            {STATE_EXP_NUMBER, {
                {CHAR_NUMBER, STATE_EXP_NUMBER},}
            }
        };
        State st = STATE_INTIAL;
        for (char c: s) {
            CharType type = toCharType(c);
            if (transfer[st].find(type) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][type];
            }
        }
        // 整数, 小数, 无整数小数, 指数
        return st ==  STATE_INTEGER || st == STATE_POINT|| st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};
// @lc code=end

