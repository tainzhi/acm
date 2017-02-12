#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Strlen(char *str) {
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    str[i] = '\0';
    return i;
}

int Convert(char *number) {
    int result;
    if (strcmp("zero", number) == 0)
        result = 0;
    else if (strcmp("one", number) == 0)
        result = 1;
    else if (strcmp("two", number) == 0)
        result = 2;
    else if (strcmp("three", number) == 0)
        result = 3;
    else if (strcmp("four", number) == 0)
        result = 4;
    else if (strcmp("five", number) == 0)
        result = 5;
    else if (strcmp("six", number) == 0)
        result = 6;
    else if (strcmp("seven", number) == 0)
        result = 7;
    else if (strcmp("eight", number) == 0)
        result = 8;
    else 
        result = 9;
    return result;
}

int GetValue(char *number1, char *number2) {
    /* printf("GetValue %d %d\n", Convert(number1), Convert(number2)); */
    return Convert(number2) + Convert(number1) * 10;
}

int main()
{
    char array[50];
    char onenumber[30], twonumber[30];
    int len, i, tag1, tag2, ope1, ope2, sindex1, sindex2, tagindex, onezero, twozero;
    while (fgets(array, 50, stdin) != NULL) {
        len = Strlen(array);
        if (len == 0)
            break;
        tag1 = tag2 = 0;
        sindex1 = sindex2 = 0;
        onezero = twozero = 0;
        tagindex = 0; // 0 begin; 1 char; 2 space; 3 +; 4 =
        ope1 = ope2 = 0;
        for (i = 0; array[i] != '\0'; ++i) {
            if (isalpha(array[i])) {
                if (tag1 == 0) {
                    onenumber[sindex1++] = array[i];
                } else if (tag2 == 0) {
                    twonumber[sindex2++] = array[i];
                }

            } else if (array[i] == '+') {
                if (tag1 == 1 && tag2 == 1) {
                    ope1 = GetValue(onenumber, twonumber);
                    onezero = 1;
                } else {
                    ope1 = Convert(onenumber);
                }
                tag1 = tag2 = 0;
            } else if (array[i] == ' ') {
                if (sindex1 > 0) {
                    onenumber[sindex1++] = '\0';
                    sindex1 = 0;
                    tag1 = 1;
                } else if (sindex2 > 0) {
                    twonumber[sindex2++] = '\0';
                    sindex2 = 0;
                    tag2 = 1;
                }
            } else if (array[i] == '=') {
                    if (tag1 == 1 && tag2 == 1) {
                        ope2 = GetValue(onenumber, twonumber);
                        twozero = 1;
                    } else
                        ope2 = Convert(onenumber);
                    tag1 = tag2 = 0;
            }
        }
        if (ope1 == 0 && ope2 == 0 && onezero == 0 && twozero == 0)
            break;
        /* printf("%d + %d = %d\n", ope1, ope2, ope1 + ope2); */
        printf("%d\n", ope1 + ope2);
    }
    return 0;
}



