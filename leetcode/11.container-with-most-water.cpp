class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if (size == 2) return min(height[0], height[1]);
        int lo = 0;
        int hi = size - 1;
        bool lomin;
        int min = 0;
        int area = 0;
        while (lo < hi)
        {
            lomin = height[lo] < height[hi] ? true : false;
            min = lomin ? height[lo] : height[hi];
            area = min * (hi - lo) > area ? min * (hi - lo) : area;
            lomin ? lo++ : hi--;
        }
        return area;
    }
};