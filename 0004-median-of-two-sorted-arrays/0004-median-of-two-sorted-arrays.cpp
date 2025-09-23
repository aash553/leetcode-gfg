class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m) return findMedianSortedArrays(nums2, nums1); // ensure nums1 is smaller

        int low = 0, high = n;
        int left = (n + m + 1) / 2;  // number of elements in left partition
        int N = n + m;

        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = left - mid1;

            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n) ? nums1[mid1] : INT_MAX;
            int r2 = (mid2 < m) ? nums2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                if (N % 2 == 1)
                    return max(l1, l2);  // odd
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0; // even
            }
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};
