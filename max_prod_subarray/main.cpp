class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int min_i = nums[0];
        int max_i = nums[0];
        int max_n = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int max_t = max_i;
            max_i = std::max(max_i * nums[i], nums[i]);
            max_i = std::max(max_i, min_i * nums[i]);

            min_i = std::min(min_i * nums[i], nums[i]);
            min_i = std::min(min_i, max_t * nums[i]);

            if (max_i > max_n)
                max_n = max_i;
        }

        return max_n;
    }
};
