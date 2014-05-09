#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define N 1010

void Reverse(char *p_start, char *p_end)
{
    if (p_start == NULL || p_end == NULL || p_start >= p_end)
        return;
    while (p_start < p_end)
    {
        char temp = *p_end;
        *p_end = *p_start;
        *p_start = temp;
        p_start++;
        p_end--;
    }
}

int main()
{
    char input_string[N];
    int k;
    while (scanf("%s%d", input_string, &k) != EOF)
    {
        int length = strlen(input_string);
        if (length > 1 && k > 0 && k % length)
        {
            k %= length;
            Reverse(input_string, input_string+k-1);
            Reverse(input_string+k, input_string+length-1);
            Reverse(input_string, input_string+length-1);
        }
        puts(input_string);
    }
}


