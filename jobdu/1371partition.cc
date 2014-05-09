#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;

void RandomPartiton(int number[], int left, int right, int k)
{
    int random_at = left+(rand()%(right-left+1));
    int pivort_key = number[random_at];
    number[random_at] = number[left];
    number[left] = pivort_key;
    int low = left, high = right;
    while (low <= high)
    {
        if (number[low] <= pivort_key)
            low++;
        else
        {
            swap(number[low], number[high]);
            high--;
        }
    }
    //printf("low = %d, high =%d\n", low, high);
    number[left] = number[high];
    number[high] = pivort_key;
    if (high == k)
        return;
    else if (high > k)
        RandomPartiton(number, left, high-1, k);
    else
        RandomPartiton(number, high+1,right, k);
}

int main()
{
    int number[200000];
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF)
    {
        for (int i=0; i<n; i++)
            scanf("%d", &number[i]);
        /*
        if (k <= 0 || k > n)
            throw "input error";
        */
        if (k < n)
        {
            srand(time(NULL));
            RandomPartiton(number, 0, n-1, k);
        }
        sort(number, number + k);
        for (int i=0; i<k; i++)
            printf("%d%c", number[i], i==k-1?'\n':' ');
    }
    return 0;
}
        
