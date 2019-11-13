class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x >= 0 && x <= 9) return true;
        if (x % 10 == 0) return false;
        int v = 0;
        while (x > v)
        {
            v = v * 10 + x % 10;
            x /= 10;
        }
        return x == v || x == v/10;
    }
};