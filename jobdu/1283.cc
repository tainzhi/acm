#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    string input_string;
    int tag[26];
    while (cin>>input_string)
    {
        for (int i=0; i<26; i++)
            tag[i] = 0;
        for (int i=0; i<input_string.length(); i++)
            tag[input_string[i] - 'A']++;
        int outcome_index = -1;
        for (int i=0; i<input_string.length(); i++)
            if (tag[input_string[i] - 'A'] == 1)
            {
                outcome_index = i;
                break;
            }
        cout<<outcome_index<<endl;
    }
    return 0;
}
