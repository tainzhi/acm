class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int maxLen = 0;
        string ret;
        for (auto is: d) {
            int ii = 0;
            for (char c: s) {
                if (c == is[ii]) {
                    ii++;
                }
            }
            if (ii == is.size()) {
                if (maxLen < is.size() || (maxLen == is.size() && (ret.compare(is) > 0))) {
                    maxLen = is.size();
                    ret = is;
                } else if (maxLen == is.size()) {}
            }
        }
        return ret;
    }
};