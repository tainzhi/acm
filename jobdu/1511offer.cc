#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next_link;
};

void RecursionOutput(node * head)
{
    if (head == NULL)
        return;
    else
    {
        RecursionOutput(head->next_link);
        printf("%d\n", head->value);
    }
}

int main()
{
    int input_num;
    node * head = NULL, *p = NULL;
    while (scanf("%d", &input_num) != EOF)
    {
        if (input_num == -1)
            break;
        if (head == NULL)
        {
            head = (node *)malloc(sizeof(node));
            head->value = input_num;
            head->next_link = NULL;
            p = head;
        }
        else
        {
            p->next_link = (node *)malloc(sizeof(node));
            p->next_link->value = input_num;
            p->next_link->next_link = NULL;
            p = p->next_link;
        }
    }
    RecursionOutput(head);
    return 0;
}
        

