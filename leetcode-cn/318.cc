class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mask[words.size()], len[words.size()];
        if (words.empty()) return 0;
        for (int i = 0; i < words.size(); i++) {
            len[i]  = words[i].length();
            mask[i] = 0;
            for (char c: words[i]) {
                mask[i] |= 1<<(c- 'a');
            }
        }
        int ret = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i+1; j < words.size(); j++) {
                if ((mask[i]&mask[j]) == 0) {
                    ret = std::max(ret, len[i] * len[j]);
                }
            }
        }
        return ret;
    }
};