#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n,x;
    while (cin>>n>>x)
    {
        int sum = 0, c;
        for (int i=0; i<n; i++)
        {
            cin>>c;
            sum += c;
        }
        if (sum < 0)
            sum *= -1;
        int count_min = 0, x_max = x;
        while (sum > 0)
        {
            if (sum >= x_max)
            {
                sum -= x_max;
                count_min++;
            }
            else
            {
                x_max--;
                if (x_max == 0)
                    break;
            }
        }
        cout<<count_min<<endl;
    }
    return 0;
}

