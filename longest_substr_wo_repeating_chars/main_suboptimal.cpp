class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int j = 0;
        int n = s.length();
        int maxLen = 0;
        int charMap[256];
        for (int i = 0; i < n; i++) {
            memset(charMap, 0, sizeof(charMap));
            for (j = i; j < n; j++) {
                if (charMap[s[j]])
                    break;
                charMap[s[j]] = 1;
            }
            if ((j - i) > maxLen)
                maxLen = j - i;
            if (maxLen > (n - i))
                break;
        }
        return maxLen;
    }
};

// O(n^2)
