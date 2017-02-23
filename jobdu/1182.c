#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

int Strlen(char *str) {
    int len = 0;
    while (str[len] != '\n' && str[len] != '\0' && str[len])
        ++len;
    return len;
}

int Scanf(char *buffer, char *input, int index) {
    int count = 0;
    while (input[index] != '\0' && input[index] != '\n' && input[index] != ' ')
        buffer[count++] = input[index++];
    return count;
}

char string[MAX_SIZE];
char buffer[MAX_SIZE];
int number[MAX_SIZE];

int main() {
    while (fgets(buffer, MAX_SIZE, stdin) != NULL) {
        int length = Strlen(buffer);
        int number_count = 0;
        if (length == 0)
            break;
        else {
            for (int i = 0; i < MAX_SIZE; ++i)
                number[i] = 0;
            --length; //remove "."
            /* printf("length=%d\n", length); */
            buffer[length] = '\0';
            int buffer_index = 0, index;
            number_count = 0;
            while (buffer_index < length) {
                index = Scanf(string, buffer, buffer_index);
                /* printf("index=%d\n", index); */
                if (index > 0) {
                    buffer_index += index;
                    number[number_count++] = index;
                } else {
                    ++buffer_index;
                }
            }
            printf("%d", number[0]);
            for (int i = 1; i < number_count; ++i)
                printf(" %d", number[i]);
            printf("\n");
        }
    }
    return 0;
}
