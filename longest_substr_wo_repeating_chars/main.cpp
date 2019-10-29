class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int i = 0, j = 0;
        int n = s.length();
        int maxLen = 0;
        int charMap[256];
        memset(charMap, 0, sizeof(charMap));
        while (i < n && j < n) {
            if (!charMap[s[j]]) {
                charMap[s[j++]] = 1;
                if ((j - i) > maxLen)
                    maxLen = j - i;
            }
            else {
                charMap[s[i++]] = 0;
            }
        }
        return maxLen;
    }
};

// O(n)
