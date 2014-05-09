#include <cstdio>
#include <cstring>
#include <cstdlib>

unsigned int GetNum(char *number, int begin, int end)
{
    unsigned int exp = 1;
    unsigned int outcome = 0;
    while (end >= begin)
    {
        outcome += ((number[end]-'0') * exp);
        exp *= 10;
        end--;
    }
    return outcome;
}

int main()
{
    char str[20];
    while (gets(str))
    {
        bool flag = true;
        int length = strlen(str);
        if (length == 0)
            flag = false;
        int number_begin = -1, number_end = -1, outcome;
        //puts(str);
        for (int i=0; i<length; i++)
        {
            //printf("str[%d]=%c\n", i, str[i]);
            if (str[i] >= '0' && str[i] <= '9')
            {
                number_begin = i;
                break;
            }
        }
        for (int i=number_begin; i<length; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
                number_end = i;
            else
                flag = false;
        }
        //printf("begin=%d end=%d\n", number_begin, number_end);
        if ((str[0] == '-'))
        {
            if (length == 1)
                flag = false;
            else if (number_begin != 1 || number_end != length-1)
                flag = false;
            else
            {
                unsigned int temp = GetNum(str, number_begin, number_end);
                if (temp > 2147483648)
                    flag = false;
                else
                    outcome = (int)(-1) * (int)(temp);
            }
        }
        else if ((str[0] == '+'))
        {
            if (length == 1)
                flag =false;
            else if (number_begin != 1 || number_end != length-1)
                flag = false;
            else
            {
                unsigned int temp = GetNum(str, number_begin, number_end);
                if (temp > 2147483647)
                    flag = false;
                else
                    outcome = (int)(temp);
            }
        }
        else
        {
            if (number_begin != 0 || number_end != length-1)
                flag = false;
            else
            {
                unsigned int temp = GetNum(str, number_begin, number_end);
                if (temp > 2147483647)
                    flag = false;
                else
                    outcome = (int)(temp);
            }
        }
        if (flag)
            printf("%d\n", outcome);
        else
            printf("My God\n");
    }
    return 0;
}

