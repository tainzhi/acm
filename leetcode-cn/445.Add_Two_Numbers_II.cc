/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto dummy = new ListNode(0);
        // ListNode *dummy = (ListNode *)malloc(sizeof(ListNode));
        dummy->val = 0;
        ListNode *pa = l1, *pb = l2, *head;
        int acn = 0, bcn = 0;
        while (pa != NULL)
        {
            acn++;
            pa = pa->next;
        }
        while (pb != NULL)
        {
            bcn++;
            pb = pb->next;
        }
        int dif = 0;
        if (acn >= bcn)
        {
            dif = acn - bcn;
            dummy->next = l1;
            pa = l1;
            pb = l2;
        }
        else
        {
            dif = bcn - acn;
            dummy->next = l2;
            pa = l2;
            pb = l1;
        }
        while (dif > 0)
        {
            pa = pa->next;
            --dif;
        }
        add(pa, pb);
        if (add10(dummy->next) == 1)
        {
            dummy->val = 1;
            return dummy;
        }
        else
        {
            return dummy->next;
        }
    }

    void add(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL && l2 == NULL)
        {
            return;
        }
        else
        {
            l1->val += l2->val;
            add(l1->next, l2->next);
        }
    }

    int add10(ListNode *l)
    {
        if (l == NULL){
            return 0;
        }
        else
        {
            int sum = l->val + add10(l->next);
            if (sum >= 10)
            {
                l->val = sum % 10;
                return sum / 10;
            }
            else
            {
                l->val = sum;
                return 0;
            }
        }
    }
};

int main() {
    ListNode  l1 = ListNode(5), l2 = ListNode(6);
    ListNode * result = Solution().addTwoNumbers(&l1, &l2);
}