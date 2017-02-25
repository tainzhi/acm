#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string in;
    sort(in, in + in.length());
    while (cin>>in) {
        do {
            cout<<in<<endl;
        } while (next_permutation(in, in + end));

    }
    return 0;
}
