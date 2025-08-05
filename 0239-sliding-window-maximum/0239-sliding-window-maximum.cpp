class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;  // stores indices
        vector<int> result;

        for (int i = 0; i < n; i++) {
            // Remove indices which are out of the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Remove smaller elements as they are not useful
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // Add current element index
            dq.push_back(i);

            // Add the max element of current window to the result
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
