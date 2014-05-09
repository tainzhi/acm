#include <iostream>
#include <cmath>

using namespace std;
typedef long long LL;

LL GCD(LL b, LL a)
{
    LL temp;
    while (b)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

LL LCM(LL a, LL b)
{
    return a * b / GCD(a, b);
}

int main()
{
    int n, m;
    LL divisor[20];
    while (cin>>n>>m)
    {
        LL outcome = 0;
        for (int i=0; i<m; i++)
            cin>>divisor[i];
        for (int status=1; status <(1<<m); status++)
        {
            LL bit = -1;
            LL mul=1;
            for (int i=0; i<m; i++)
                if (status & (1<<i))
                {
                    bit *= -1;
                    mul = LCM(mul, divisor[i]);
                }
            outcome += bit * (n/mul);
        }
        cout<<n - outcome<<endl;
    }
    return 0;
}
