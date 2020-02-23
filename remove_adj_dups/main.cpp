class Solution {
public:
    std::string removeDuplicates(std::string S) {
        std::vector<char> v;
        std::string T(S);

        for (int i = 0; i < T.length(); i++) {
            if (v.empty()) {
                v.push_back(T[i]);
            }
            else {
                if (T[i] == v[v.size() - 1]) {
                    v.pop_back();
                }
                else {
                    v.push_back(T[i]);
                }
            }
        }
        T = std::string(v.begin(), v.end());
  
        return T;
    }
};
