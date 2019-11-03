class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        std::string::iterator l, r, prev;
        for (auto &s : strs) {
            if (idx == 0) {
                l = s.begin();
                r = s.end();
            }
            else {
                std::string::iterator cur = s.begin();
                std::string::iterator prev = l;
                l = s.begin();
                while (*cur == *prev && cur != s.end() && prev != r) {
                    cur++;
                    prev++;
                }
                r = cur;
            }
            idx++;
        }
        return std::string {l, r};
    }
};
