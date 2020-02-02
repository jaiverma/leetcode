struct Node {
    int val;
    int min;
    Node *next;
    Node(int x) : val(x), min(0), next(nullptr) {};
};

class MinStack {
private:
    Node *s_top;
public:
    /** initialize your data structure here. */
    MinStack() {
        s_top = nullptr;
    }
    
    void push(int x) {
        Node *n = new Node(x);
        if (s_top == nullptr) {
            s_top = n;
            n->min = x;
        }
        else {
            n->min = std::min(x, s_top->min);
            n->next = s_top;
            s_top = n;
        }
    }
    
    void pop() {
        if (s_top != nullptr) {
            Node *temp = s_top;
            s_top = s_top->next;
            temp->next = nullptr;
            delete(temp);
        }        
    }
    
    int top() {
        if (s_top == nullptr)
            return -1;
        return s_top->val;
    }
    
    int getMin() {
        if (s_top == nullptr)
            return -1;
        return s_top->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
