class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if (size == 2) return min(height[0], height[1]);
        int lo = 0;
        int hi = size - 1;
        bool lomin = height[lo] < height[hi] ? true : false;
        int min = lomin ? height[lo] : height[hi];
        int area = min * (hi - lo);
        while (lo < hi)
        {
            if (lomin)
            {
                lo++;
                lomin = height[lo] < height[hi] ? true : false;
                min = lomin ? height[lo] : height[hi];
                area = min * (hi - lo) > area ? min * (hi - lo) : area;
            }
            else
            {
                hi--;
                lomin = height[lo] < height[hi] ? true : false;
                min = lomin ? height[lo] : height[hi];
                area = min * (hi - lo) > area ? min * (hi - lo) : area;
            }
        }
        return area;
    }
};