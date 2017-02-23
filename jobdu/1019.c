#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 210

int Strlen(char *str) {
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0')
        ++i;
    str[i] = '\0';
    return i;
}

int prioriy[4][4] = {
    /* row: stack top; column: stack in */
    /* -1: <, 1: > */
    /******   +    -   *   /   **********/
    /* + */ { 1,  1, -1, -1},
    /* - */ { 1,  1, -1, -1},
    /* * */ { 1,  1,  1,  1},
    /* / */ { 1,  1,  1,  1},
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
        default:
            return -1;
    }
}

int Convert(char *str, int n) {
    int result = 0, bit = 1, i;
    for (i = n - 1; i >= 0; i--) {
        result += bit * (str[i] - '0');
        bit *= 10;
    }
    return result;
}

double Function(double oter1, double oter2, int ope) {
    double result;
    switch(ope) {
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
    return result;
}

int MyScanf(char *buffer, char *input, int begin) {
    int count = 0;
    while (input[begin] != ' ' && input[begin] != '\n' && input[begin] != '\0')
        buffer[count++] = input[begin++];
    return count;
}

char operator_stack[MAX_SIZE];
double operand_stack[MAX_SIZE];
int rpe[MAX_SIZE]; // Reverse Polish Expression
int tag[MAX_SIZE]; // 0 is number, 1 is operator

int main()
{
    char str[MAX_SIZE];
    while (fgets(str, MAX_SIZE, stdin)) {
        if (Strlen(str) == 0) {
            break;
        } else if (str[0] == '0' && Strlen(str) == 1) {
            break;
        } else {
            int length = Strlen(str);
            int index_in = 0, index_buffer = 0;
            char buffer[MAX_SIZE];
            int rpe_i = 0;
            int operator_top = 0;
            int operand_top = 0;
            while (index_in < length) {
                index_buffer = MyScanf(buffer, str, index_in);
                if (index_buffer >= 1) {
                    buffer[index_buffer] = '\0';
                    int in_stack_operator = GetIndex(buffer[0]);
                    if (in_stack_operator == -1) { // number
                        rpe[rpe_i] = Convert(buffer, index_buffer);
                        tag[rpe_i++] = 0;
                    } else { // operator
                        if (operator_top == 0) {
                            operator_stack[++operator_top] = in_stack_operator;
                        } else {
                            int stack_top_operator = operator_stack[operator_top];
                            if (prioriy[stack_top_operator][in_stack_operator] < 0)
                                operator_stack[++operator_top] = in_stack_operator;
                            else {
                                while (operator_top > 0 && prioriy[(int)operator_stack[operator_top]][in_stack_operator] > 0) {
                                    rpe[rpe_i] = operator_stack[operator_top--];
                                    tag[rpe_i++] = 1;
                                }
                                operator_stack[++operator_top] = in_stack_operator;
                            } 
                        }
                    }
                    index_in += index_buffer;
                } else {
                    ++index_in;
                }
            }
            while (operator_top > 0) {
                rpe[rpe_i] = operator_stack[operator_top--];
                tag[rpe_i++] = 1;
            }
            operand_top = 0;
            double first, second;
            for (int i = 0; i < rpe_i; ++i)
                if (tag[i] == 0) {
                    operand_stack[++operand_top] = rpe[i];
                } else {
                    second = operand_stack[operand_top--];
                    first = operand_stack[operand_top--];
                    first = Function(first, second, rpe[i]);
                    operand_stack[++operand_top] = first;
                }
            printf("%.2lf\n", operand_stack[1]);
        }
    }
    return 0;
}

