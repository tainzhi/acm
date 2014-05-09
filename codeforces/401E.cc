#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int prime[100010], prime_count;

void GetPrime()
{
    int tag[100010];
    prime_count = 0;
    for (int i=1; i<100010; i++)
        tag[i] = 0;
    tag[1] = tag[2] = tag[3] = 0;
    for (int i=2; i<100010; i++)
        if (tag[i] == 0)
        {
            for (int j=i+i; j<100010; j += i)
                tag[j] = 1;
        }
    for (int i=1; i<100010; i++)
        if (tag[i] == 0)
            prime[prime_count++] = i;
}

int main()
{
    int n, m,l, r, p;
    GetPrime();
    while (cin>>n>>m)
    {
        cin>>l>>r>>p;
        int cn = 0, cm = 0;
        for (int i=0; i<prime_count; i++)
        {
            if (prime[i] <= n)
                cn++;
            else
                break;
        }
        for (int i=0;i<prime_count; i++)
        {
            if (prime[i] <= m)
                cm++;
            else
                break;
        }
        //cout<<"cn="<<cn<<" cm="<<cm<<endl;
        long long ans = 0, l2 = l * l, r2 = r * r;
        for (int i=0; i<cn; i++)
            for (int j=0; j<cm; j++)
            {
                if (i == j && i > 0)
                    continue;
                long long rac = prime[i] * prime[i] + prime[j] * prime[j];
                if (rac >= l2 && rac <= r2)
                    ans = (ans +  (n-prime[i]+1)*(m-prime[j]+1)*2) % p;
            }
        cout<<"ans="<<ans<<endl;
        if (1>=l)
            ans = (ans + (n*(m+1) + (n+1)*m))%p;
        cout<<ans<<endl;
    }
    return 0;
}
