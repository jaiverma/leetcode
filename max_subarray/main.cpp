#include <iostream>
#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_i = nums[0];
        int max_n = nums[0];
        
        if (nums.size() == 1)
            return max_n;

        for (int i = 1; i < nums.size(); i++) {
            max_i = std::max(nums[i], max_i + nums[i]);
            if (max_i > max_n)
                max_n = max_i;
        }

        return max_n;
    }
};
