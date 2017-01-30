#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1010

struct student {
    char id[30];
    int grade;
} students[MAX_SIZE];

int Compare(const void *a, const void *b) {
    if (((struct student *)a)->grade < ((struct student *)b)->grade) {
        return 1;
    } else if (((struct student *)a)->grade > (((struct student *)b)->grade)) {
        return -1;
    } else {
        return strcmp(((struct student *)a)->id, ((struct student *)b)->id);
    }
}

void Swap(int i, int j) {
    struct student temp;
    strcpy(temp.id, students[j].id);
    temp.grade = students[j].grade;
    strcpy(students[j].id, students[i].id);
    students[j].grade = students[i].grade;
    strcpy(students[i].id, temp.id);
    students[i].grade = temp.grade;
}
void Sort(int n) {
    int i, j;
    for (i = 1; i < n; i++)
        for (j = n - 1; j >= i; j--) {
            if (strcmp(students[j].id, students[j - 1].id) < 0) {
                Swap(j, j - 1);
            }
        }
    for (i = 1; i < n; i++)
        for (j = n - 1; j >= i; j--) {
            if (students[j].grade > students[j - 1].grade) {
                Swap(j, j - 1);
            }
        }
}

int main()
{
    int n, m, g, problems[10];
    int better, did, i, j;
    while (scanf("%d", &n) != EOF) {
        better = 0;
        if (n == 0)
            break;
        scanf("%d %d", &m, &g);
        for (i = 0; i < m; i++)
            scanf("%d", &problems[i]);
        for (i = 0; i < n; i++) {
            scanf("%s", (students[i].id));
            students[i].grade = 0;
            scanf("%d", &m); 
            while (m--) {
                scanf("%d", &did);
                students[i].grade += problems[did - 1];
            }
            if (students[i].grade >= g)
                better++;
        }
        qsort(students, n, sizeof(struct student), Compare);
        printf("%d\n", better);
        for (i = 0; i < better; i++) {
            printf("%s %d\n",  students[i].id, students[i].grade);
        }

    }
    return 0;
}
