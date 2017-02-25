#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head);

int main() {
    struct ListNode *head = NULL, *p, *temp;
    int tt;
    scanf("%d", &tt);
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = tt;
    head->next = NULL;
    p = head;
    while (scanf("%d", &tt) != EOF) {
        if (tt == 0)
            break;
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = tt;
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
    head = insertionSortList(head);
    for (struct ListNode *temp = head; temp; temp = temp->next)
        printf("!%d\n", temp->val);
    return 0;
}

struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
       return head;
    else {
        struct ListNode *p, *tp, *temp, *temp2;
        p = head;
        while (p->next != NULL) {
            if (p->val > p->next->val) {
                if (head->val > p->next->val) {
                    temp = p->next->next;
                    p->next->next = head;
                    head = p->next;
                    p->next = temp;
                    p = head;
                } else {
                    tp = head;
                    while (tp->next->val <= p->next->val)
                        tp = tp->next;
                    temp = tp->next;
                    tp->next = p->next;
                    temp2 = p->next->next;
                    p->next->next = temp;
                    p->next = temp2;
                }
            } else {
                p = p->next;
            }
        }
        return head;
    }
}
