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
    int size;
    ListNode *head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        int size = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            size++;
        }
        this->size = size;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int idx = std::rand() % size;
        ListNode* cur = head;
        while (idx--) {
            cur = cur->next;
        }
        return cur->val;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
