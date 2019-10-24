class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int ml = 0, mr = 0;
        int maxLength = 1;
        int i = 0, j = 0;
        int start = 0;
        int end = s.length() - 1;
        
        for (int mid = start; mid <= end; mid++) {
            ml = (mid > start) ? mid - 1 : start;
            mr = (mid < end) ? mid  + 1 : end;

            while (ml >= start && s[mid] == s[ml])
                ml--;
            while (mr <= end && s[mid] == s[mr])
                mr++;

            if (mr - ml - 1 > maxLength) {
                i = ml + 1;
                j = mr - 1;
                maxLength = mr - ml - 1;
            }

            while (ml >= start && mr <= end) {
                if (s[ml] == s[mr]) {
                    if ((mr - ml + 1) > maxLength) {
                        maxLength = mr - ml + 1;
                        i = ml;
                        j = mr;
                    }
                    ml--;
                    mr++;
                    continue;
                }
                break;
            }
        }
        return s.substr(i, maxLength);
    }
};
