#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

void Clockwise90(int &n, int &m, int &i, int &j)
{
    int ti = i, tj = j;
    i = tj;
    j = n - ti + 1;
    swap(n, m);
}

void Clockwise180(int &n, int &m, int &i, int &j)
{
    int ti = i, tj = j;
    i = n - ti + 1;
    j = m - tj + 1;
}

void Clockwise270(int &n, int &m, int &i, int &j)
{
    int ti = i, tj = j;
    i = m - tj + 1;
    j = ti;
    swap(n, m);
}

void HorizontalRotate(int &n, int &m, int &i, int &j)
{
    int ti = i, tj = j;
    i = ti;
    j = m - tj + 1;
}

int main()
{
    int n, m, x, y, z, p;
    void (*clock_wise[3])(int &, int &, int &, int&);
    void (*counter_clock_wise[3])(int &, int &, int &, int&);
    clock_wise[0] = Clockwise90, clock_wise[1] = Clockwise180, clock_wise[2] = Clockwise270;
    counter_clock_wise[0] = Clockwise270, counter_clock_wise[1] = Clockwise180, counter_clock_wise[2] = Clockwise90;
    while (cin>>n>>m>>x>>y>>z>>p)
    {
        int xk, yk;
        while (p--)
        {
            int tn = n, tm = m;
            cin>>xk>>yk;
            if (x % 4)
            {
                /*
                int x_temp = x%4 -1;
                cout<<"x_temp="<<x_temp<<endl;
                */
                clock_wise[x%4-1](tn, tm, xk, yk);
                //printf("xk=%d yk=%d\n", xk, yk);
            }
            if (y % 2)
            {
                /*
                int y_temp = y%2;
                cout<<"y_temp="<<y_temp<<endl;
                */
                HorizontalRotate(tn, tm, xk, yk);
            }
            if (z % 4)
            {
                /*
                int z_temp = z%4 - 1;
                cout<<"z_temp="<<z_temp<<endl;
                */
                counter_clock_wise[z%4-1](tn, tm, xk, yk);
            }
            cout<<xk<<" "<<yk<<endl;
        }
    }
    return 0;
}








