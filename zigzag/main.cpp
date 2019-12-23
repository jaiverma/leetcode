#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1)
            return s;

        std::vector<int> sz(numRows, 0);
        int step = 1;
        int rno = 0;
        for (int i = 0; i < s.length(); i++) {
            sz[rno]++;
            rno += step;
            if ((rno == 0) || (rno == numRows - 1))
                step = -step;
        }

        step = 1;
        rno = 0;
        std::vector<int> cnos(numRows, 0);
        std::string a(s.length(), 0);
        for (int i = 0; i < s.length(); i++) {
            if (rno == 0)
                a[cnos[rno]] = s[i];
            else
                a[std::accumulate(sz.begin(), sz.begin() + rno, 0) + cnos[rno]] \
                    = s[i];
            cnos[rno] += 1;
            rno += step;
            if ((rno == 0) || (rno == numRows - 1))
                step = -step;
        }

        return a;
    }
};

int main() {
    Solution s = Solution();
    std::string t = "PAYPALISHIRING";
    int r = 4;
    std::cout << s.convert(t, r) << std::endl;
}
