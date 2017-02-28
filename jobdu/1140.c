#include <stdio.h>
#include <string.h>

int count = 0;
void EightQueen(int position[], int current, int target) {
    if (current > 8) {
        ++count;
        if (count == target) {
            for (int i = 1; i <= 8; ++i)
                printf("%d", position[i]);
            printf("\n");
        }
    } else {
        for (int col = 1; col <= 8; ++col) {
            int well = 1;
            for (int i = 1; i < current; ++i) {
                if (position[i] == col ||
                        (current - i) == (col - position[i]) ||
                        (i - current) == (col - position[i])) {
                    well = 0;
                    break;
                }
            }
            if (well) {
                position[current] = col;
                EightQueen(position, current + 1, target);
            }
        }
    }
}

int main() {
    int cases, position[10];
    while (scanf("%d", &cases) != EOF) {
        int query;
        for (int i = 0; i < cases; ++i) {
            count = 0;
            scanf("%d", &query);
            EightQueen(position, 1, query);
        }
    }
    return 0;
}

