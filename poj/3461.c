#include <stdio.h>
#include <string.h>
#define MAXSIZE_W 10010
#define MAXSIZE_T 1000010
void getNext(int len, char * tstr, int * next) {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < len) {
        if ( j == -1 || tstr[i] == tstr[j]) {
            i++;
            j++;
            next[i] = j;
        }else {
            j = next[j];
        }
    }
}

int main()
{
    int ncase;
    char wstr[MAXSIZE_W], tstr[MAXSIZE_T];
    int next[MAXSIZE_T];
    int wlen, tlen;
    scanf("%d", &ncase);
    while (ncase--) {
        scanf("%s", wstr);
        wlen = strlen(wstr);
        scanf("%s", tstr);
        tlen = strlen(tstr);
        if (wlen > tlen) {
            printf("0\n");
        }
        else {
            getNext(wlen, wstr, next);
            int i = -1, j = -1, count = 0;
            while (i < tlen) {
                if (j == -1 || tstr[i] == wstr[j]) {
                    i++;
                    j++;
                } else {
                    j = next[j];
                }
                if (j >= wlen) {
                    count++;
                    j = next[j];
                }
            }
            printf("%d\n", count);
        }
    }
    return 0;
}
