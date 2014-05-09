#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x, y;
    while (cin>>x>>y)
        cout<<atan2(x, y)<<endl;
    return 0;
}
