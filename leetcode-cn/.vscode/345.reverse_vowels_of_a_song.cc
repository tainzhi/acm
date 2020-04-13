#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {

    if (c == 'a' || c == 'o' || c == 'e' || c == 'u' || c == 'i' ||
        c == 'A' || c == 'O' || c == 'E' || c == 'U' || c == 'I') {
        return true;
    } else {
        return false;
    }
}

string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
        if (isVowel(s[left]) && isVowel(s[right])) {
            std::swap(s[left++], s[right--]);
        } else if (left < s.size() && !isVowel(s[left])) {
            left++;
        } else if (right > 0 && !isVowel(s[right])) {
            right--;
        }
    }
    return s;
}

int main() {
    string s;
    while(cin >> s) {
        cout<<reverseVowels(s)<<endl;
    }
    return 0;
}