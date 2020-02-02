#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = t;
            }
        }
    }
};

int main() {
    Solution s = Solution();
    std::vector<std::vector<int>> v {{1, 2, 3},
                                     {4, 5, 6},
                                     {7, 8, 9}};
    s.rotate(v);

    int n = v.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
