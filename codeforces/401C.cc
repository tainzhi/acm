#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m;
    string card;
    while (cin>>n>>m)
    {
        if (n-1>m || 2*(n+1) < m)
            cout<<"-1"<<endl;
        else if (n-1 == m)
        {
            for (int i=0; i<m; i++)
                cout<<"01";
            cout<<"0"<<endl;
        }
        else if (n == m)
        {
            for (int i=0; i<n; i++)
                cout<<"10";
            cout<<endl;
        }
        else
        {
            int sm = m - (n+1), sn = n;
            while (sn > 0)
            {
                if (sm > 0)
                {
                    sm--;
                    cout<<"110";
                }
                else
                    cout<<"10";
                sn--;
            }
            if (sm)
                cout<<"11"<<endl;
            else
                cout<<"1"<<endl;
        }
    }
    return 0;
}

