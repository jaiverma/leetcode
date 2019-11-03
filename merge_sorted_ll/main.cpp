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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        bool first = true;
        ListNode *head = nullptr;
        ListNode *cur = nullptr;

        while (l1 != nullptr && l2 != nullptr) {
            if (first) {
                if (l1->val < l2->val) {
                    head = l1;
                    l1 = l1->next;
                }
                else {
                    head = l2;
                    l2 = l2->next;
                }
                cur = head;
                first = false;
            }
            else {
                if (l1->val < l2->val) {
                    cur->next = l1;
                    l1 = l1->next;
                }
                else {
                    cur->next = l2;
                    l2 = l2->next;
                }
                cur = cur->next;
            }    
        }

        while (l1 != nullptr) {
            if (head == nullptr) {
                head = l1;
                cur = head;
            }
            else {
                cur->next = l1;
                cur = cur->next;
            }
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            if (head == nullptr) {
                head = l2;
                cur = head;
            }
            else {
                cur->next = l2;
                cur = cur->next;
            }
            l2 = l2->next;
        }

        return head;
    }
};
