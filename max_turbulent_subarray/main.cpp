class Solution {
public:
    int maxTurbulenceSize(std::vector<int>& A) {
        int max_i = 1;
        int max_n = 1;

        if (A.size() == 1)
            return max_n;
        
        for (int i = 1; i < A.size(); i++) {
            if (i % 2 == 0) {
                if (A[i] > A[i-1])
                    max_i++;
                else
                    max_i = 1;
            }
            else {
                if (A[i] < A[i-1])
                    max_i++;
                else
                    max_i = 1;
            }
            if (max_i > max_n)
                max_n = max_i;
        }

        max_i = 1;

        for (int i = 1; i < A.size(); i++) {
            if (i % 2 == 0) {
                if (A[i] < A[i-1])
                    max_i++;
                else
                    max_i = 1;
            }
            else {
                if (A[i] > A[i-1])
                    max_i++;
                else
                    max_i = 1;
            }
            if (max_i > max_n)
                max_n = max_i;
        }

        return max_n;
    }
};
