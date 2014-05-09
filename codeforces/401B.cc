#include <iostream>

using namespace std;

int main()
{
    int x,m;
    int tag[4010];
    while (cin>>x>>m)
    {
        int a, b, c;
        for (int i=1; i<x; i++)
            tag[i] = 0;
        int maximum = x -1;
        while (m--)
        {
            cin>>a;
            if (a == 1)
            {
                cin>>b>>c;
                maximum -= 2;
                tag[b] = tag[c] = 1;
            }
            else
            {
                cin>>b;
                maximum -= 1;
                tag[b] = 1;
            }
        }
        int before, new_begin = 0, minmum = 0, count = 0;
        for (int i=1; i<x; i++)
        {
            if (tag[i] == 0 && new_begin == 0)
            {
                before = i;
                new_begin = 1;
                count++;
            }
            else if (tag[i] == 0 && new_begin == 1)
                count++;
            else if (tag[i] == 1)
            {
                new_begin = 0;
                count = 0;
            }
            if (tag[i+1] == 1 && i+1 <x || i + 1 == x)
                minmum += (count - count/2);
        }
        cout<<minmum<<" "<<maximum<<endl;
    }
    return 0;
}




