#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Strlen(char *str) {
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        ++i;
    str[i] = '\0';
    return i;
}

int Prioriy[4][4] = {
    /* row: stack top; column: stack in */
    /* -1: <, 0: =, 1: > */
    /******   +    -   *   /   **********/
    /* + */ { 0,  0,  1,  1},
    /* - */ { 0,  0,  1,  1},
    /* * */ {-1, -1,  0,  0},
    /* / */ {-1, -1,  0,  0}
};

int GetIndex(char op) {
    switch(op) {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
    }
    return 0;
}

int Convert(char *str, int n) {
    int result = 0, bit = 1, i;
    for (i = n - 1; i >= 0; i--) {
        result += bit * (str[i] - '0');
        bit *= 10;
    }
    return result;
}

double Function(int op, double oter1, double oter2) {
    double result;
    /* printf("Fucntion op=%d %.2lf %.2lf\n", op, oter1, oter2); */
    switch(op) {
        case 0:
            result =  oter1 + oter2;
            break;
        case 1:
            result = oter1 - oter2;
            break;
        case 2:
            result = oter1 * oter2;
            break;
        case 3:
            result = oter1 / oter2;
            break;
    }
    /* printf("Function result=%.2lf\n", result); */
    return result;
}

int main()
{
    char str[205], nstr[205];
    int rep[205];
    char tag[205]; /*0: number, 1: operator*/
    double stack[205];
    int top;
    char stack_op[205];
    int stop;
    int i, j, k, ind;
    double oter1, oter2;
    while (fgets(str, 205, stdin)) {
        if (Strlen(str) == 0) {
            break;
        } else if (str[0] == '0') {
            break;
        } else {
            j = 0;
            k = 0;
            top = 0;
            stop = 0;
            for (i = 0; str[i] != 0; i++) {
                if (str[i] == ' ') {
                    if (j != 0) {
                        tag[k] = 0;
                        rep[k++] = Convert(nstr, j);
                        j = 0;
                    }
                } else if (str[i] >= '0' && str[i] <= '9') {
                    nstr[j++] = str[i];
                } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
                    ind = GetIndex(str[i]);
                    if (stop == 0) {
                        stack_op[++stop] = ind;
                    } else {
                        if (Prioriy[(int)(stack_op[stop])][ind] >= 0) {
                            stack_op[++stop] = ind;
                        } else {
                            tag[k] = 1;
                            rep[k++] = stack_op[stop];
                            stack_op[stop] = ind;
                        }
                    }
                }
            }
            tag[k] = 0;
            rep[k++] = Convert(nstr, j);
            while (stop > 0) {
                tag[k] = 1;
                rep[k++] = stack_op[stop--];
            }
            /* printf("k=%d\n", k); */
            /* for (i = 0; i < k; i++) { */
            /*     printf("%d->%d\n", tag[i], rep[i]); */
            /* } */
            top = 0;
            stop = 0;
            for (i = 0; i < k; i++) {
                if (tag[i] == 0) {
                    stack[++top] = rep[i];
                } else {
                        oter1 = stack[top--];
                        oter2 = stack[top--];
                        stack[++top] = Function(rep[i], oter2, oter1);
                    }
                }
            printf("%.2lf\n", stack[1]);
            /* printf("-------\n"); */
        }


    }
    return 0;
}

