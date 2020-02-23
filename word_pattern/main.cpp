class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
        std::vector<std::string> s;
        std::unordered_map<string, bool> done;
        std::unordered_map<char, string> m;
        std::istringstream ss(str);
        do { 
            std::string word; 
            ss >> word;
            if (word.length() > 0)
                s.push_back(word);
         } while (ss);
        // for (int i = 0; i < s.size(); i++) {
        //     printf("'%s'\n", s[i].c_str());
        // }
        if (pattern.length() != s.size()) {
            // printf("size mismatch\n");
            return false;
        }
        int i = 0, j = 0;
        while (i < pattern.length() && j < s.size()) {
            if (m.find(pattern[i]) == m.end()) {
                if (done.find(s[j]) != done.end()) {
                    // printf("%s is already in done\n", s[j].c_str());
                    return false;
                }
                m[pattern[i]] = s[j];
                done[s[j]] = true;
            }
            else {
                if (m[pattern[i]] != s[j]) {
                    // printf("%c doesn't map to %s\n", pattern[i], s[j].c_str());
                    return false;
                }
            }
            i++;
            j++;
        }
        return true;
    }
};
