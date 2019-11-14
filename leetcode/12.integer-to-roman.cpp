class Solution {
public:
    string intToRoman(int num) {
        string rst;
        string words[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int nums[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int tmp;
        for (int i = 12; i >=0; i--)
        {
            if ((tmp = num / nums[i]) != 0)
            {
                while (tmp-- > 0)
                {
                    rst.append(words[i]);
                }
                num %= nums[i];
            }
        }
        return rst;
    }
};