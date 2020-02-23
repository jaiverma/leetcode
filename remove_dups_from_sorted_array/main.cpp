class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (auto it = nums.begin(); it != nums.end();) {
            if (m.find(*it) == m.end()) {
                m[*it] = 1;
                it++;
            }
            else {
                nums.erase(it);
            }
        }
        return nums.size();
    }
};
