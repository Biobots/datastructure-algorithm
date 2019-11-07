class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0) return "";
        int maxlen = 1;
        int begin = 0;
        std::vector<int> tri;
        std::vector<int> db;
        char mem[3];
        mem[0] = s[0];
        mem[1] = s[1];
        mem[2] = s[2];
        if (mem[0] == mem[2]) tri.push_back(1);
        if (mem[0] == mem[1]) db.push_back(0);
        if (mem[2] == mem[1]) db.push_back(1);
        for (int i = 3; i < len; i++)
        {
            mem[0] = mem[1];
            mem[1] = mem[2];
            mem[2] = s[i];
            if (mem[0] == mem[2]) tri.push_back(i-1);
            if (mem[2] == mem[1]) db.push_back(i-1);
        }
        size_t vlen = tri.size();
        for (size_t i = 0; i < vlen; i++)
        {
            int j = 1;
            int c = tri[i];
            while (c+j<len && c-j>=0 && s[c+j] == s[c-j])
            {
                j++;
            }
            j--;
            if (2 * j + 1 > maxlen)
            {
                maxlen = 2 * j + 1;
                begin = c - j;
            }
        }
        vlen = db.size();
        for (size_t i = 0; i < vlen; i++)
        {
            int j = 1;
            int c = db[i];
            while (c+1+j<len && c-j>=0 && s[c+1+j] == s[c-j])
            {
                j++;
            }
            j--;
            if (2 * j + 2 > maxlen)
            {
                maxlen = 2 * j + 2;
                begin = c - j;
            }
        }
        return s.substr(begin, maxlen);
    }
};