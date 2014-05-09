#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>

#define EPS 1e-8

using namespace std;

struct cPoint{
    int x, y;
    double polar;
}polygon[10010];

double CrossProduct(cPoint &p1, cPoint &p2, cPoint &p3, cPoint &p4)
{
    double x1 = p2.x - p1.x, y1 = p2.y - p1.y;
    double x2 = p4.x - p3.x, y2 = p4.y - p3.y;
    return x1 * y2 - x2 * y1;
}

int compare(const void *a, const void *b)
{
    if (((cPoint*)a)->polar - ((cPoint*)b)->polar < -EPS)
        return -1;
    else if (((cPoint*)a)->polar - ((cPoint*)b)->polar > EPS)
        return 1;
    else
    {
        if (((cPoint*)a)->x < ((cPoint*)b)->x < 0)
            return -1;
        else if (((cPoint*)a)->x > ((cPoint*)b)->x > 0)
            return 1;
        else
            return 0;
    }
}

void GrahamScan(stack<int> &mystack, int n)
{
    mystack.push(0);
    for (int i=1; i<n; i++)
    {
        while (mystack.size() > 2)
        {
            int current = mystack.top();
            mystack.pop();
            int top_point = mystack.top();
            if (CrossProduct(polygon[current], polygon[top_point], polygon[i], polygon[current])< -EPS)
                continue;
            else
            {
                mystack.push(current);
                break;
            }
        }
        mystack.push(i);
    }
}

double GetArea(stack<int> &mystack, int n)
{
    double outcome = 0;
    //cout<<"size="<<mystack.size()<<endl;
    while (mystack.size() >= 3)
    {
        int p1 = mystack.top();
        mystack.pop();
        //cout<<polygon[p1].x<<"***p1***"<<polygon[p1].y<<endl;
        int p2 = mystack.top();
        //cout<<polygon[p2].x<<"***p2***"<<polygon[p2].y<<endl;
        outcome += 0.5 * (CrossProduct(polygon[0], polygon[p2], polygon[0], polygon[p1]));
    }
    return outcome;
}

int main()
{
    int n;
    while (cin>>n)
    {
        int xleft = 10000, left_low;
        for (int i=0; i<n; i++)
        {
            cin>>polygon[i].x>>polygon[i].y;
            if (xleft > polygon[i].x)
                left_low = i, xleft = polygon[i].x;
            else if (xleft == polygon[i].x)
            {
                if (polygon[i].y < polygon[left_low].y)
                    left_low = i;
            }
        }
        for (int i=0; i<n; i++)
        {
            if (i == left_low)
                continue;
            else
            {
                polygon[i].polar = atan2(polygon[i].y - polygon[left_low].y, polygon[i].x - polygon[left_low].x);
            }
        }
        swap(polygon[left_low], polygon[0]);
        qsort(polygon+1, n-1, sizeof(cPoint), compare);
        stack<int> mystack;
        GrahamScan(mystack, n);
        cout<<(int)(GetArea(mystack, n)/50)<<endl;
    }
    return 0;
}
