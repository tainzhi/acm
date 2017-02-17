#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MONKEY_SIZE 10010
#define MAX_MONKEY_NAME_SIZE 110

typedef struct StructMonkey {
    int strong;
    int eat;
    int least_eat;
    char name[MAX_MONKEY_NAME_SIZE];
}Monkey;
Monkey monkeys[MAX_MONKEY_SIZE];

int Compare1(const void *a, const void *b) {
    Monkey *m1 = (Monkey *)a;
    Monkey *m2 = (Monkey *)b;
    if (m1->strong < m2->strong)
        return 1;
    else if (m1->strong > m2->strong)
        return -1;
    else {
        return strcmp(m1->name, m2->name);
    }
}

int Compare2(const void *a, const void *b) {
    Monkey *m1 = (Monkey *)a;
    Monkey *m2 = (Monkey *)b;
    return strcmp(m1->name, m2->name);
}

int main() {
    int monkey_number, query_number;
    while (scanf("%d %d", &monkey_number, &query_number) != EOF) {
        for (int i = 0; i < monkey_number; ++i)
            scanf("%s %d %d", monkeys[i].name, &monkeys[i].strong,
                    &monkeys[i].eat);
        qsort(monkeys, monkey_number, sizeof(Monkey), Compare1);
        int least_eat = 1;
        monkeys[0].least_eat =  least_eat;
        for (int jj = 1; jj < monkey_number; ++jj) {
            least_eat += monkeys[jj - 1].eat;
            monkeys[jj].least_eat = least_eat;
        }
        qsort(monkeys, monkey_number, sizeof(Monkey), Compare2);
        Monkey *p;
        Monkey monkey;
        while (--query_number >= 0) {
            scanf("%s", monkey.name);
            p = (Monkey*)bsearch(&monkey, monkeys, monkey_number, sizeof(Monkey), Compare2);
            printf("%d\n", p->least_eat);
        }
    }
    return 0;
}



