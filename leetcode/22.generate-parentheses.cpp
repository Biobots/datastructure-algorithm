class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) return rst;
        dfs(n, n, "");
        return rst;
    }
    vector<string> rst;
    void dfs(int left, int right, string str)
    {
        if(left==0 && right==0)
        {
            rst.push_back(str);
            return;
        }
        if(left>0) dfs(left-1,right,str+"(");
        if(left<right) dfs(left,right-1,str+")");
        return;
    }
};