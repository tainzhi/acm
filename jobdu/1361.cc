#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

#define N 1000100

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
    while (gets(input_string))
    {
        int length = strlen(input_string);
        Reverse(input_string, input_string + length - 1);
        char *p_begin, *p_end, *point = input_string;
        while (*point != '\0')
        {
            while (*point == ' ')
                point++;
            p_begin = point;
            while (*point != ' ' && *point != '\0')
                point++;
            p_end = point - 1;
            Reverse(p_begin, p_end);
        }
        puts(input_string);
    }
    return 0;
}


