#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void displayLL(ListNode *head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode *merged = nullptr;
        ListNode *mergedCur = nullptr;
        std::vector<ListNode*> head;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr)
                head.push_back(lists[i]);
        }

        while (head.size() > 0) {
            int minIdx = 0;
            int minVal = head[0]->val;
            for (int i = 1; i < head.size(); i++) {
                if (head[i]->val < minVal) {
                    minVal = head[i]->val;
                    minIdx = i;
                }
            }

            if (mergedCur == nullptr) {
                merged = mergedCur = head[minIdx];
            }
            else {
                mergedCur->next = head[minIdx];
                mergedCur = mergedCur->next;
            }

            head[minIdx] = head[minIdx]->next;
            if (head[minIdx] == nullptr)
                head.erase(head.begin() + minIdx);
        }

        return merged;
    }
};

int main() {
    auto s = Solution();

    ListNode *ll1 = new ListNode(1);
    ll1->next = new ListNode(3);
    ll1->next->next = new ListNode(5);

    ListNode *ll2 = new ListNode(2);
    ll2->next = new ListNode(4);
    ll2->next->next = new ListNode(6);

    ListNode *ll3 = new ListNode(0);
    ll3->next = new ListNode(7);
    ll3->next->next = new ListNode(8);

    displayLL(ll1);
    displayLL(ll2);
    displayLL(ll3);
    std::vector<ListNode*> v = {ll1, ll2, ll3};

    auto m = s.mergeKLists(v);
    displayLL(m);
}