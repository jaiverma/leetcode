void printV(std::vector<int> &v, int start) {
    for (int i = start; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std:cout << std::endl;
}

class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        std::stack<int> st;
        int i = 0;
        int j = 0;
        while (i < pushed.size() && j < popped.size()) {
            if (st.empty()) {
                st.push(pushed[i++]);
                continue;
            }
            if (st.top() == popped[j]) {
                st.pop();
                j++;
            }
            else {
                st.push(pushed[i++]);
            }
        }
        
        while (i < pushed.size()) {
            st.push(pushed[i++]);
        }
        
        while (j < popped.size()) {
            if (st.top() == popped[j]) {
                st.pop();
                j++;
            }
            else
                break;
        }
        
        // std::cout << "pushed: ";
        // printV(pushed, i);
        // std::cout << "popped: ";
        // printV(popped, j);
        
        return (i == pushed.size() && j == popped.size());
    }
};
