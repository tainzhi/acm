#include <string>
#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int number)
{
    if (number == 1)
        return true;
    for (int i=2; i<=(int)(sqrt(number)); i++)
        if (number % i == 0)
            return false;
    return true;
}

bool GetReverseValue(int number)
{
    int reverse[10], len = 0;
    while (number)
    {
        reverse[len++] = number % 10;
        number /= 10;
    }
    for (int i=0, j=len-1; i<len/2; i++, j--)
        if (reverse[i] != reverse[j])
            return false;
    return true;
}

int main()
{
    int n;
    cin>>n;
    while (true)
    {
        if (GetReverseValue(n) && IsPrime(n))
        {
            cout<<n<<endl;
            break;
        }
        n++;
    }
    return 0;
}
