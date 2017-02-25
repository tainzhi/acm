#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    string in;
    char str[10];
    // cout<<"in="<<in<<endl;
    while (scanf("%s", str) != EOF) {
        int len = strlen(str);
        sort(str, str + len);
        do {
            printf("%s\n", str);
        } while (next_permutation(str, str + len));
        printf("\n");
    }
    return 0;
}
