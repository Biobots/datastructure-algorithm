class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0) return (nums2[(n - 1) / 2] + nums2[n / 2]) / 2.0;
        if (n == 0) return (nums1[(m - 1) / 2] + nums1[m / 2]) / 2.0;
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        // nums1   nums2
        // 2m+1    2n+1
        // 2m      2n
        int mptr = m;
        int nptr = n;
        int l1 = nums1[(m - 1) / 2];
        int r1 = nums1[m / 2];
        int l2 = nums2[(n - 1) / 2];
        int r2 = nums2[n / 2];
        int lo = 0; int hi = 2 * m;
        while (hi >= lo)
        {
            mptr = (lo + hi) / 2;
            nptr = m + n - mptr;
            l1 = (mptr == 0) ? INT_MIN : nums1[(mptr - 1) / 2];
            r1 = (mptr == 2 * m) ? INT_MAX : nums1[mptr / 2];
            l2 = (nptr == 0) ? INT_MIN : nums2[(nptr - 1) / 2];
            r2 = (nptr == 2 * n) ? INT_MAX : nums2[nptr / 2];
            if (l1 > r2) hi = mptr - 1;
            else if (l2 > r1) lo = mptr + 1;
            else break;
        }
        l1 = l1 > l2 ? l1 : l2;
        r1 = r1 < r2 ? r1 : r2;
        return (l1 + r1) / 2.0;
    }
};