class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        while (s[i] == 0x20)     // skip white spaces
            i++;

        if ((s[i] != 0x2b) &&       // skip if not [+-0..9]
            (s[i] != 0x2d) &&
            (s[i] < 0x30) &&
            (s[i] > 0x39)) {
            printf("%c : 0x%x\n", s[i], s[i]);
            std::cout << "shit\n";
            return 0;
        }

        int neg = 1;
        int num = 0;
        if (s[i] == 0x2b) {
            neg = 1;
            i++;
        }
        else if (s[i] == 0x2d) {
            neg = -1;
            i++;
        }
        while (s[i] >= 0x30 && s[i] <= 0x39) {  // while in [0..9]
            if (num > INT_MAX / 10) {
                if (neg == -1)
                    return INT_MIN;
                return INT_MAX;
            }
            num *= 10;
            int toAdd = s[i] - 0x30;
            if (num > INT_MAX - toAdd) {
                if (neg == -1)
                    return INT_MIN;
                return INT_MAX;
            }
            num += toAdd;
            i++;
        }
        num *= neg;
        return num;
    }
};
