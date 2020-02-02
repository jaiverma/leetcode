#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        long long allProd = 1;
        int nZero = 0;
        for (auto &i : nums) {
            if (i != 0)
                allProd *= i;
            else
                nZero++;
        }

        std::vector<int> output(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (nZero > 1)
                    output[i] = 0;
                else
                    output[i] = allProd;
            }
            else {
                if (nZero > 0)
                    output[i] = 0;
                else
                   output[i] = allProd / nums[i];
            }
        }

        return output;
    }
};

int main() {
    auto s = Solution();
    std::vector<int> v = {1,2,3,4};
    auto x = s.productExceptSelf(v);
    for (auto &i : x) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
