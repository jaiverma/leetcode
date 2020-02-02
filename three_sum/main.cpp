class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::set<std::vector<int>> ansS;
        std::unordered_map<int, int> numCount;
        for (auto &i : nums) {
            numCount[i]++;
        }
        if (numCount[0] == nums.size() && nums.size() >= 3) {
            ansS.insert(std::vector<int> {0, 0, 0});
            return std::vector<std::vector<int>> (ansS.begin(), ansS.end());
        }
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int idx = binarySearch(nums, j + 1, n - 1, -(nums[i] + nums[j]));
                if (idx != -1)
                    ansS.insert(std::vector<int> {nums[i], nums[j], nums[idx]});
            }
        }
        return std::vector<std::vector<int>> (ansS.begin(), ansS.end());
    }
    
    int binarySearch(std::vector<int> &v, int start, int end, int x) {
        while (start <= end) {
            int mid = (start + end) / 2;
            if (v[mid] == x)
                return mid;
            else if (v[mid] < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return -1;
    }
};
