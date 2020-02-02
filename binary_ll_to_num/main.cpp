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
    int getDecimalValue(ListNode* head) {
        int num = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            num |= cur->val;
            num <<= 1;
            cur = cur->next;
        }
        num >>= 1;
        return num;
    }
};
