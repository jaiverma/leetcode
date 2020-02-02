class Solution {
public:
    std::vector<int> decompressRLElist(std::vector<int>& nums) {
        std::vector<int> v;
        for (auto i = nums.begin(); i != nums.end(); i += 2) {
            for (int j = 0; j < *i; j++) {
                v.push_back(*(i + 1));
            }
        } 
        return v;
    }
};
