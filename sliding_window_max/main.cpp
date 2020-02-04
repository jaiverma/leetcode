class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if (nums.size() == 0)
            return std::vector<int> {};
        if (nums.size() == 1)
            return std::vector<int> {nums[0]};

        std::deque<int> q;
        std::vector<int> ans;
        ans.reserve(nums.size() - k + 1);
        int i = 0;
        while (i < k && i < nums.size()) {
            if (q.empty())
                q.push_back(i);
            else {
                while (!q.empty() && nums[q.back()] < nums[i])
                    q.pop_back();
                q.push_back(i);
            }
            i++;
        }
        ans.push_back(nums[q.front()]);

        for (i = 1; i < nums.size() - k + 1; i++) {
            while (!q.empty() && q.front() < i)
                q.pop_front();

            if (q.empty())
                q.push_back(i + k - 1);
            else {
                while (!q.empty() && nums[q.back()] < nums[i + k - 1])
                    q.pop_back();
                q.push_back(i + k - 1);
            }
            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};
