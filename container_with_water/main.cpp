#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        auto i = height.begin();
        auto j = height.end() - 1;
        unsigned long long maxAr = 0;

        while (i < j) {
            unsigned long long ar = (j - i) * std::min(*i, *j);
            if (ar > maxAr)
                maxAr = ar;
            
            if (*i > *j)
                j--;
            else
                i++;
        }

        return maxAr;
    }
};

int main() {
    auto s = Solution();
    std::vector<int> v = {1,8,6,2,5,4,8,3,7};
    std::cout << s.maxArea(v) << std::endl;
}
