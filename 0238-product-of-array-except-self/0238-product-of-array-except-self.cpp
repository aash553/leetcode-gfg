class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Step 1: store left products in ans
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        // Step 2: multiply by right products on the fly
        int R = 1;  // running product from the right
        for(int i = n-1; i >= 0; i--) {
            ans[i] = ans[i] * R;
            R *= nums[i];
        }

        return ans;
    }
};
