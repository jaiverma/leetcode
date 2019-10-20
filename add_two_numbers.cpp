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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *headL1 = l1;
        ListNode *headL2 = l2;
        ListNode *sumL = nullptr;
        ListNode *curNode = nullptr;
        int carry = 0;
        while (headL1 && headL2) {
            int sum = headL1->val + headL2->val + carry;
            carry = sum / 10;
            ListNode *digit = new ListNode(sum % 10);
            if (!sumL) {
                sumL = digit;
                curNode = sumL;
            }
            else {
                curNode->next = digit;
                curNode = curNode->next;
            }
            headL1 = headL1->next;
            headL2 = headL2->next;
        }
        
        while (headL1) {
            int sum = headL1->val + carry;
            curNode->next = new ListNode(sum % 10);
            carry = sum / 10;
            headL1 = headL1->next;
            curNode = curNode->next;
        }
        
        while (headL2) {
            int sum = headL2->val + carry;
            curNode->next = new ListNode(sum % 10);
            carry = sum / 10;
            headL2 = headL2->next;
            curNode = curNode->next;
        }
        
        if (carry > 0) {
            curNode->next = new ListNode(carry);
        }
        
        return sumL;
    }
};
