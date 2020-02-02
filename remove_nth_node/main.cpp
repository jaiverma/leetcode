
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *new_h = nullptr;
        
        while (cur != nullptr && cur->val == val) {
            cur = cur->next;
        }
        new_h = cur;
        
        while (cur != nullptr) {
            if (cur->val != val) {
                prev = cur;
                cur = cur->next;
                continue;
            }
            prev->next = cur->next;
            cur = cur->next;
        }
        
        return new_h;
    }
};
