#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    int n, m;
    while (cin>>n)
    {
        if (n==0)
            break;
        cin>>m;
        if (n == 1)
            cout<<"1"<<endl;
        else
        {
            list<int> number;
            for (int i=1; i<=n; i++)
                number.push_back(i);
            list<int>::iterator current = number.begin();
            //cout<<"**************"<<number.size()<<endl;
            while (number.size() > 1)
            {
                for (int i=1; i<=m; i++)
                {
                    current++;
                    if (current == number.end())
                        current = number.begin();
                }
                list<int>::iterator next = current;
                if (current == number.begin())
                    current = number.end();
                current--;
                number.erase(current);
                current = next;
            }
            cout<<*current<<endl;
        }
    }
    return 0;
}



                    
