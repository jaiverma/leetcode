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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        // get size of linked list
        ListNode *cur = head;
        int len = 0;
        while (cur != nullptr) {
            cur = cur->next;
            len++;
        }

        if (len == 1)
            return true;

        int mid = len / 2;
        ListNode *left = nullptr, *right = nullptr;
        cur = head;
        for (int i = 0; i < mid - 1; i++) {
            cur = cur->next;
        }
        left = cur;
        right = (len % 2 == 0) ? cur->next : cur->next->next;
        ListNode *rev = nullptr;
        reverseLinkedList(head, left->next, &rev);

        while (left != nullptr && right != nullptr) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    void reverseLinkedList(ListNode *head, ListNode *end, ListNode **r) {
        if (head == nullptr)
            return;
        _reverseLinkedList(head, head->next, end, r);
    }

    void _reverseLinkedList(ListNode *c, ListNode *n, ListNode *e, ListNode **r) {
        if (n == e) {
            *r = c;
            (*r)->next = nullptr;
            return;
        }
        _reverseLinkedList(n, n->next, e, r);
        n->next = c;
        c->next = nullptr;
    }
};
