class Solution {
public:
    int reverse(int x) {
        long int tmp = 0;
        while (x != 0) {
            tmp = tmp * 10 + x % 10;
            if (tmp > INT_MAX || tmp < INT_MIN)
                return 0;
            x /= 10;
        }
        return tmp;
    }
};
