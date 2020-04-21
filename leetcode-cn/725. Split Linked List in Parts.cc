/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * }
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {

        int len = 0;
        ListNode* p = root, *last, *head;
        while (p != NULL) {
            ++len;
            p = p->next;
        }
        int w = len / k, remain = len % k;
        vector<ListNode*> result;
        p = root;
        for (int i = 0; i < k; i++) {
            result.push_back(p);
            for (int j = 0; j < w; j++) {
                if (p != NULL) {
                    last = p;
                    p = p->next;
                }
            }
            if (remain > 0) {
                if (p!= NULL) {
                    last = p;
                    p = p->next;
                }
                --remain;
            }
            if (last != NULL) {
                last->next = NULL;
            }
        }
        return result;
    }
};