#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s, int i, int j) {
    while (i < j) {
        if (s[i++] != s[j--]) {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return isPalindrome(s, i, j - 1) || isPalindrome(s, i+1, j);
        }
    }
    return true;
}

int main() {
    string s;
    while (cin >> s) {
        cout<<(validPalindrome(s) ? 1: 0)<<endl;
    }
    return 0;
}