class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string track = "";
        backTrace(num, target, 0, 0, track, 0, result);
        return result;
    }

    void backTrace(string num, int target, int index, long currentValue, string &track, long lastOperator, vector<string> &result) {
        if (index == num.size()) {
            if (currentValue == target) {
                result.push_back(track);
            }
            return;
        }
        int len = track.size();
        for (int i = index; i < num.size(); i++) {
            string str = num.substr(index, i - index + 1);
            long val = stol(str);
            if (index == 0) {
                track += str;
                backTrace(num, target, i + 1, val, track, val, result); track.resize(len);
            } else {
                track += "+" + str;
                backTrace(num, target, i+1, currentValue + val, track, val, result);
                track.resize(len);

                track += "-" + str;
                backTrace(num, target, i+1, currentValue - val, track, val * (-1), result);
                track.resize(len);

                track += "*" + str;
                backTrace(num, target, i+1, currentValue - lastOperator + lastOperator * val, track, lastOperator * val, result);
                track.resize(len);
            }
            if (val == 0) return;

        }
    }
};