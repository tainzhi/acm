#include <iostream>
#include <string>

using namespace std;

int bit[17][1000100];
typedef unsigned long long ULL;

int main()
{
    int n, m, c;
    ULL ans;
    while (cin>>n>>m)
    {
        ans = 0;
        for (int i=0; i<17; i++)
            for (int j=0; j<n; j++)
                bit[i][j] = 0;
        //cout<<"11111"<<endl;
        for (int i=0; i<n; i++)
        {
            cin>>c;
            for (int j=0; j<17; j++)
                if ((1ULL<<j)&c)
                    bit[j][i] = 1;
        }
        //cout<<"11111"<<endl;
        for (int i=0; i<17; i++)
        {
            int k=0;
            for (int j=0; j<n; j++)
            {
                if (bit[i][j])
                    k++;
                else
                {
                    ans += (ULL)(1ULL<<i)*(k+1)*k/2;
                    k=0;
                }
            }
            if (k)
                ans += (ULL)(1ULL<<i)*(k+1)*k/2;
        }
        //cout<<"****"<<ans<<endl;
        int p, v;
        while (m--)
        {
            cin>>p>>v;
            p--;
            for (int i=0; i<17; i++)
            {
                if (!((1ULL<<i)&v) == bit[i][p])
                {
                    int begin = 0, end = 0;
                    int t = bit[i][p] ? -1 : 1;
                    bit[i][p] += t;
                    for (int j = p -1; j >= 0 && bit[i][j]; j--)
                        begin++;
                    for (int j = p +1; j < n && bit[i][j]; j++)
                        end++;
                    ans += (ULL)(t)*(1ULL<<i) *((begin+end +1) *(begin+end+2)/2 - (begin+1)*begin/2 - (end+1)*end/2);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

