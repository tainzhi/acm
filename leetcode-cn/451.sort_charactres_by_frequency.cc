#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string frequencySort(string s) {
    map<char, int> nums;
    for (int i = 0; i < s.length(); i++) {
        ++nums[s[i]];
    }
    vector<pair<char, int>> char_nums(nums.begin(), nums.end());
    std::sort(char_nums.begin(), char_nums.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });
    string result;
    for (vector<pair<char, int>>::iterator iter = char_nums.begin(); iter!= char_nums.end(); iter++) {
        while (iter->second) {
            result += iter->first;
            iter->second--;
        }
    }
    return result;

}

int main() {
    string str;
    while (cin >>str) {
        cout<<frequencySort(str)<<endl;
    }
    return 0;
}