#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class MySum{
    public:
        MySum() {++n, sum += n;}
        static void Reset() {n=0, sum = 0;}
        static unsigned int GetSum()
        {
            return sum;
        }
    private:
        static unsigned int n;
        static unsigned int sum;
};

int main()
{
    int n;
    while (cin>>n)
    {
        MySum::Reset();
        MySum * input = new MySum[n];
        delete []input;
        cout<<MySum::GetSum<<endl;
    }
    return 0;
}



            
