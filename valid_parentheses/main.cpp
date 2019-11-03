class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (auto &i : s) {
            switch (i) {
                case '(':
                case '[':
                case '{':
                    st.push(i);
                    break;
                case ')':
                    if (st.empty())
                        return false;
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (st.empty())
                        return false;
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (st.empty())
                        return false;
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                    break;
                default:
                    break;
            }
        }
        return st.empty();
    }
};
