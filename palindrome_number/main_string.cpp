class Solution {
public:
    bool isPalindrome(int x) {
        std::string x_str = std::to_string(x);
        int l = 0, r = x_str.length() - 1;
        while (l < r) {
            if (x_str[l++] != x_str[r--])
                return false;
        }
        return true;
    }
};
