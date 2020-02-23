/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    std::unordered_map<Node*,Node*> m;
    Node* copyNode(Node *x) {
        if (m.find(x) == m.end()) {
            Node* n = new Node(x->val);
            m[x] = n;
            if (x->next == nullptr) 
                n->next = nullptr;
            else
                n->next = copyNode(x->next);
            if (x->random == nullptr)
                n->random = nullptr;
            else
                n->random = copyNode(x->random);
        }
        return m[x];
    }
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return head;

        Node* cur = head;
        Node* newL = nullptr;
        Node* newCur = nullptr;

        while (cur != nullptr) {
            if (newL == nullptr) {
                newL = copyNode(cur);
                newCur = newL;
            }
            else {
                newCur = copyNode(cur);
                cur = cur->next;
                newCur = newCur->next;
            }
        }
        return newL;
    }
};
