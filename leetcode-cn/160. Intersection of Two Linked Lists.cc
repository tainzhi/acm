/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        while (pa != NULL) {
            pb = headB;
            while (pb != NULL) {
                if (pb == pa) {
                    return pa;
                }
                pb = pb->next;
            }
            pa = pa->next;
        }
        return null;
    }

    ListNode *_getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa = headA, *pb = headB;
        int step = 0;
        while (pa != NULL && pb != NULL) {
            if (pa == pb) {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
            if (pa == NULL && step < 2) {
                pa = headB;
                ++step;
            }
            if (pb == NULL && step < 2) {
                pb = headA;
                ++step;
            }
        }
        return NULL;
    }
};
