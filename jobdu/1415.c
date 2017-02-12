#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100010

int queue[MAX_SIZE], front, end, size;

int Push(int x) {
    if (((front + 1) % size) == end) {
        return 0;
    } else {
        queue[front] = x;
        front = (front + 1) % size;
        return 1;
    }
}

int Pop() {
    if (end == front)
        return 0;
    else {
        end = (end + 1) % size;
        return 1;
    }
}

int IsEmpty() {
    return end == front ? 1 : 0;
}

int IsFull() {
    return ((front + 1) % size == end) ? 1 : 0;
}

int main() {
    int m, n;
    char failed[] = "failed";
    char yes[] = "yes";
    char no[] = "no";
    char instruction[20];
    int data;
    while (scanf("%d %d", &n, &m) != EOF) {
        size = m + 1;
        while (n--) {
            scanf("%s", instruction);
            if (strcmp("Push", instruction) == 0) {
                scanf("%d", &data);
                if (Push(data) == 0)
                    printf("%s\n", failed);
            } else if (strcmp("Pop", instruction) == 0) {
                scanf("%d", &data);
                if (Pop() == 0)
                    printf("%s\n", failed);
            } else if (strcmp("Query", instruction) == 0) {
                scanf("%d", &data);
                if ((end + data - 1) % size < front)
                    printf("%d\n", queue[(end + data - 1) % size]);
                else
                    printf("%s\n", failed);
            } else if (strcmp("Isempty", instruction) == 0) {
                printf("%s\n", IsEmpty() ? yes : no);
            } else if (strcmp("Isfull", instruction) == 0) {
                printf("%s\n", IsFull() ? yes : no);
            }
        }
    }
    return 0;
}
