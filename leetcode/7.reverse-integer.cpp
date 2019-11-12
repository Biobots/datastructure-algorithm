class Solution {
public:
    int reverse(int x) {
        int min = INT_MIN;
        int max = INT_MAX;
        long rst = 0;
        while (x != 0)
        {
            rst *= 10;
            rst += x%10;
            x /= 10;
        }
        return (int)(rst <= max ? (rst >= min ? rst : 0) : 0);
    }
};