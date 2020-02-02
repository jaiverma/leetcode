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
    void deleteNode(ListNode* node) {
        ListNode *tmp = nullptr;
        while (node->next != nullptr) {
            node->val = node->next->val;
            tmp = node;
            node = node->next;
        }
        tmp->next = nullptr;
    }
};
