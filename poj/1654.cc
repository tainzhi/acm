#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Point{
    int x, y;
};

Point polygon[1000010];

int direction[10][2] = {{0,0},
    {-1,-1}, {0, -1}, {1, -1}, {-1, 0},
    {0,0},{1,0},{-1,1},{0,1},{1,1}};

long long CrossProduct(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}

int main()
{
    int test;
    cin>>test;
    while (test--)
    {
        string trace;
        cin>>trace;
        int x_begin=0, y_begin=0, count = 0;
        for (string::iterator it = trace.begin(); *it != '5'; it++)
        {
            x_begin += direction[*it-'0'][0];
            y_begin += direction[*it-'0'][1];
            polygon[count].x = x_begin;
            polygon[count].y = y_begin;
            count++;
        }
        long long int area = 0;
        for (int i=1; i<count; i++)
            area += CrossProduct(polygon[i], polygon[i-1]);
        if (area < 0)
            area *= (-1);
        if (area % 2)
            cout<<(area-1)/2 + 0.5<<endl;
        else
            cout<<area/2<<endl;
    }
    return 0;
}



