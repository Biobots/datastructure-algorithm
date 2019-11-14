class Solution {
public:
    inline int search(char c)
    {
        switch (c)
        {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int rst = 0;
        int ptr = s.size() - 1;
        int w = 0;
        int prew = -1;
        while (ptr >= 0)
        {
            w = search(s[ptr]);
            if (prew > w)
            {
                rst -= w;
            }
            else
            {
                rst += w;
                prew = w;
            }
            ptr--;
        }
        return rst;
    }
};