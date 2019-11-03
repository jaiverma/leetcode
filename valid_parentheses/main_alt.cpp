class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        std::unordered_map<char, char> m {
            {']', '['},
            {')', '('},
            {'}', '{'}
        };
        for (auto &i : s) {
            if (i == '[' || i == ']' ||
                i == '(' || i == ')' ||
                i == '{' || i == '}') {
                if (!st.empty()) {
                    auto it = m.find(i);
                    if (it != m.end()) {
                        std::cout << "it: " << it->second << std::endl;
                        std::cout << "top: " << st.top() << std::endl;
                        if (st.top() == it->second)
                            st.pop();
                        else
                            return false;
                    }
                    else {
                        st.push(i);
                    }
                }
                else {
                    st.push(i);
                }
            }
        }
        return st.empty();
    }
};
