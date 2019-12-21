class Solution {
private:
    int r;
    int c;
    int idx(int i, int j) {
        return c * i + j;
    }
    int numCols(int n , int r) {
        int c = 0;
        while (n > 0) {
            c++;
            n -= r;
            if (n > 0) {
                c += r - 2;
                n -= r - 2;
            }
        }
        return c;
    }
public:
    std::string convert(std::string s, int numRows) {
        if (s == "" || numRows < 2)
            return s;
        int n = s.length();
        this->r = numRows;
        this->c = numCols(n, numRows);
        std::string arr(this->c * this->r, ' ');

        int i = 0, j = 0, x = 0;
        while (j < this->c && x < n) {
            if ((j % (this->r - 1)) == 0) {
                i = 0;
                while (i < r && x < n) {
                    arr[idx(i, j)] = s[x];
                    i++;
                    x++;
                }
                i--;
            }
            else {
                i--;
                arr[idx(i, j)] = s[x];
                x++;
            }
            j++;
        }
        arr.erase(std::remove(arr.begin(), arr.end(), ' '), arr.end());
        return arr;
    }
};
