class Solution {
public:
    bool isLeftBrach(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    bool isRightBrach(char c) {
        return c == ')' || c == ']' || c == '}';
    }

    bool isPair(char l, char r) {
        return ((l == '(') && (r == ')')) || ((l == '{') && (r == '}')) || ((l == '[') && (r == ']'));
    }

    bool isValid(string s) {
        stack<char> sta;
        for (auto c: s) {
            if (isLeftBrach(c)) {
                sta.push(c);
            } else if (isRightBrach(c)) {
                if (sta.empty()) {
                    return false;
                } else {
                    if (isPair(sta.top(), c)) {
                        sta.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        if (sta.empty()) {
            return true;
        } else {
            return false;
        }
    }
};