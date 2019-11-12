class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        bool d[m+1][n+1] = false;
        d[0][0] = true;
        for (int i = 1; i < n + 1; i++)
        {
            d[0][i] = p[i-1] == '*' && d[0][i-2];
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                
            }
        }
    }
};