class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int index[2] = (m + n) % 2 == 0 ? {(m + n) / 2 - 1, (m + n) / 2} : {(m + n) / 2, (m + n) / 2};
        int aptr = index[0] / 2;
        int bptr = index[0] / 2;
        while (aptr < m && b < n)
        {
            
        }
    }
};