class Solution {
public:
    string getCommonPrefix(string& left, string& right)
    {
        int size = left.size() < right.size() ? left.size() : right.size();
        if (size == 0) return "";
        for (int i = 0; i < size; i++)
        {
            if (left[i] != right[i]) return left.substr(0, i);
        }
        return left.substr(0, size);
    }
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) return "";
        if (size == 1) return strs[0];
        string rst = getCommonPrefix(strs[0], strs[1]);
        int i = 2;
        while (rst != "" && i < size)
        {
            rst = getCommonPrefix(rst, strs[i]);
            i++;
        }
        return rst;
    }
};