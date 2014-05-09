#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

#define N 1010
int main()
{
    char input_string[N];
    int n;
    while (scanf("%s%d", input_string, &n) != EOF)
    {
        int length = strlen(input_string);
        if (n < 0)
            printf("error!\n");
        if (length > 1 && n > 0 && n % length)
        {
            n %= length;
            char temp = input_string[0];
            int count = 0, index=0;
            while (count < length)
            {
                    int before = (index-n + length) % length;
                    //printf("before=%d\n", before);
                    char semp = input_string[before];
                    input_string[before] = temp;
                    temp = semp;
                    index = before;
                    count++;
            }
        }
        puts(input_string);
    }
    return 0;
}
