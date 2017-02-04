#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int months[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, \\
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void ConvertIntToString(char *str, int n) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; --i) {
        if (n) {
            str[i] = '0' + n % 10;
            n /= 10;
        } else
            break;
    }
}

bool IsLeapYear(int year) {
}

int main() {
    int year, th_day, mm, dd;
    char year_str[] = "0000";
    char month_str[] = "00";
    char day_str[] = "00";
    while (scanf("%d %d", &year, &th_day) != EOF) {
        mm = -1;
        if (!((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))) {
            for (int i = 0; i < 12; i++) {
                if (th_day - months[i] >= 0) {
                    th_day -= months[i];
                    mm = i;
                } else
                    break;
            }
            if (th_day == 0) {
                dd = months[mm];
                mm += 1;
            } else {
                dd = th_day;
                mm += 2;
            }
            if (mm > 12) {
                year += 1;
                mm = 1;
            }
        } else {
            for (int i = 0; i < 12; i++) {
                if (th_day - leap_months[i] >= 0) {
                    th_day -= leap_months[i];
                    mm = i;
                } else
                    break;
            }
            if (th_day == 0) {
                dd = leap_months[mm];
                mm += 1;
            } else {
                dd = th_day;
                mm += 2;
            }
        }
        /* ConvertIntToString(year_str, year); */
        /* ConvertIntToString(month_str, mm); */
        /* ConvertIntToString(day_str, dd); */
        /* printf("%s-%s-%s\n", year_str, month_str, day_str); */
        printf("%04d-%02d-%02d\n", year, mm, dd);
    }
    return 0;
}


