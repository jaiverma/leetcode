class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> idxMap;
        for (int i = 0; i < nums.size(); i++) {
            int toFind = target - nums[i];
            auto idxItr = idxMap.find(toFind);
            if (idxItr != idxMap.end()) {
                return std::vector<int> { i, idxItr->second };
            }
            idxMap.emplace(nums[i], i);
        }
        return std::vector<int> { -1, -1 };
    }
};
