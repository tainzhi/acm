#include <iostream>
#include <vector>

using namespace std;

string findLongestWord(string s, vector<string>& d) {
    string result = "";
    for (int i = 0; i < d.size(); i++) {
        string sstr = d[i];
        int h = 0, k = 0;
        for (k = 0; k < s.size(); k++) {
            if (s[k] == sstr[h]) h++;
        }
        
        if (h == sstr.size()) {
            if ((h > result.size()) ||  (h == result.size() && sstr.compare(result) < 0)) {
                result = sstr;
            }
        }
    }
}