/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head;
        int sz = 0;
        while (cur != nullptr) {
            cur = cur->next;
            sz++;
        }
        if (sz == 1)
            return nullptr;

        cur = head;
        for (int i = 0; i < sz - n - 1; i++) {
            cur = cur->next;
        }
        if (sz - n - 1 < 0)
            head = head->next;
        else
            cur->next = cur->next->next;
        
        return head;
    }
};
