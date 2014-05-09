#include <iostream>
#include <string>

using namespace std;

bool judge(string &input, int a[], int row)
{
    int col = 12 / a[row];
    //cout<<a[row]<<"***"<<col<<endl;
    bool flag;
    for (int i=0; i<col; i++)
    {
        flag = true;
        for (int j=0; j<a[row]; j++)
        {
            //cout<<(j*col+i)<<"---"<<endl;
            if (input[j * col + i] == 'O')
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
            break;
    }
    return flag;
}

int main()
{
    int test;
    int a[] = {1, 2, 3, 4, 6, 12};
    int outcome[6];
    cin>>test;
    string input;
    while (test--)
    {
        cin>>input;
        int count = 0;
        for (int i=0; i<6; i++)
        {
            if (judge(input, a, i) == true)
                outcome[count++] = a[i];
        }
        if (count == 0)
            cout<<"0"<<endl;
        else
        {
            cout<<count;
            for (int i=0; i<count; i++)
                cout<<" "<<outcome[i]<<"x"<<12/outcome[i];
            cout<<endl;
        }
    }
    return 0;
}


