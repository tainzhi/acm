#include <stdio.h>

#define MAX_SIZE 1000010

long int nums1[MAX_SIZE];
long int nums2[MAX_SIZE];

int main()
{
    long int n, m, i, j, mid, midp, midv;
    long int mid2, midp2, midv2;
    int flag;
    while (scanf("%ld", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%ld", &nums1[i]);
        scanf("%ld", &m);
        for (j = 0; j < m; j++)
            scanf("%ld", &nums2[j]);
        mid = (n + m - 1 ) / 2;
        //printf("mid = %d\n", mid);
        i = 0;
        j = 0;
        midp = 0;
        flag = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                if (midp == mid)
                {
                    midv = nums1[i];
                    flag = 1;
                    break;
                }
                midp++;
                i++;
            } else {
                if (midp == mid)
                {
                    flag = 1;
                    midv = nums2[j];
                    break;
                }
                midp++;
                j++;
            }
        }
        while (i < n && !flag) {
            if (midp == mid) {
                midv = nums1[i];
                break;
            } else {
                midp++;
                i++;
            }
        }
        while (j < m && !flag) {
            if (midp == mid) {
                midv = nums2[j];
                break;
            } else {
                midp++;
                j++;
            }
        }
        printf("%ld\n", midv);
    }
    return 0;
}



