#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

long long dp[1<<18][100];

int main()
{
    string interger;
    int m;
    while (cin>>interger>>m)
    {
        memset(dp, 0, sizeof(long long) * (100 * (1<<18)));
        int bit[10];
        memset(bit, 0, sizeof(int) * 10);
        int len = interger.length();
        for (int i=0; i<len; i++)
        {
            int b = interger[i] - '0';
            bit[b]++;
            if (b)
                dp[1<<i][b % m] = 1;
        }
        for (int i=0; i<(1<<(len)); i++)
            for (int j=0; j<m; j++)
                if (dp[i][j])
                {
                    for (int k=0; k<len; k++)
                    {
                        if ((1<<k) & i)
                            continue;
                        int b = interger[k] - '0';
                        dp[i + (1<<k)][(j * 10 + b) % m] += dp[i][j];
                    }
                }
        long long ans = dp[(1<<len) - 1][0];
        for (int i=0; i<10; i++)
            for (int j=2; j<=bit[i]; j++)
                ans /= (long long) j;
        cout<<ans<<endl;
    }
    return 0;
}



