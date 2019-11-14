class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        bool d[m+1][n+1];
        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                d[i][j] = false;
            }
        }
        d[0][0] = true;
        for (int i = 1; i < n + 1; i++)
        {
            d[0][i] = p[i-1] == '*' && d[0][i-2];
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    d[i][j] = d[i - 1][j - 1];
                }
                if (p[j - 1] == '*')
                {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                    {
                        d[i][j] = d[i - 1][j] || d[i][j - 2];
                    }
                    else
                    {
                        d[i][j] = d[i][j - 2];
                    }
                }
            }
        }
        return d[m][n];
    }
};