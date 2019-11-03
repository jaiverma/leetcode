class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int x_l = x;
        unsigned long long y = 0;
        while (x_l > 0) {
            y = y * 10 + x_l % 10;
            x_l /= 10;
        }
        return x == y;
    }
};
