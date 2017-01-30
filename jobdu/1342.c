#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000100

char stack[MAX_SIZE];
int top;

int main() {
    char array[MAX_SIZE];
    int count, i;
    while (scanf("%s", array) != EOF) {
        top = 0;
        count = 0;
        for (i = 0; i < (int)(strlen(array)); i++) {
            if (array[i] == '(') {
                stack[++top] = array[i];
            } else if (array[i] == ')' && top >0 ) {
                    top--;
                    count += 2;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}


