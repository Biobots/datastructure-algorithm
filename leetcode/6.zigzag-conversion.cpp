class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        if (s.size() <= numRows) return s;
        int max = 2 * numRows - 2;
        int cur = max;
        int size = s.size();
        int line = (size - numRows) / max;
        int left = (size - numRows) % max;
        string ret(size, ' ');
        int j = 0;
        int i = 0;
        for (; i <= line; i++)
        {
            ret[i] = s[j];
            j += max;
        }
        if (left >= numRows - 1) ret[i] = s[j];
        else i--;
        int head = 1;
        while (head < numRows - 1)
        {
            int tmp = i + 2 * line;
            j = head;
            while (i < tmp)
            {
                ret[++i] = s[j];
                j += max - head * 2;
                ret[++i] = s[j];
                j += head * 2;
            }
            ret[++i] = s[j];
            j += max - head * 2;
            if (left >= numRows - 1 - head) ret[++i] = s[j];
            j += head * 2;
            if (left >= numRows - 1 + head) ret[++i] = s[j];
            head++;
        }
        j = numRows - 1;
        i++;
        for (; i < size; i++)
        {
            ret[i] = s[j];
            j += max;
        }
        return ret;
    }
};