class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> smap;
        for (auto c: s) {
            smap[c]++;
        }
        for (auto c: s) {
            smap[c]--;
        }
        for (auto m: smap) {
            if (m.second != 0) {
                return false;
            }
        }
        return true;
    }
};