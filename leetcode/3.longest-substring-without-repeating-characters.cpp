class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s[0] == NULL) return 0;
        map<char, int> m;
        m[s[0]] = 0;
        int i = 0;
        int j = 1;
        int tmp = 1;
        int rst = 1;
        map<char, int>::iterator iter;
        while (s[i] && s[j])
        {
            if (!s[j]) return rst;
            char a = s[j];
            iter = m.find(a);
            if (iter == m.end())
            {
                m[a] = j;
                tmp++;
                j++;
                rst = rst < tmp ? tmp : rst;
            }
            else
            {
                int index = iter->second;
                if (index < i)
                {
                    m[a] = j;
                    tmp++;
                    rst = rst < tmp ? tmp : rst;
                    j++;
                    continue;
                }
                tmp -= index - i;
                rst = rst < tmp ? tmp : rst;
                m[a] = j;
                j++;
                i = index + 1;
            }
        }
        return rst;
    }
};