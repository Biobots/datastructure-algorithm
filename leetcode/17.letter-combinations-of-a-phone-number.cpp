class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> rst;
        if(digits=="") return rst;
        for(auto d : digits)
        {
            process(rst, d);
        }
        return rst;
    }
    map<char, string> dic = {
        {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
    };
    void process(vector<string>& v, char n)
    {
        int len = v.size();
        if(len==0)
        {
            v.push_back("");
            len++;
        }
        string val = dic[n];
        int num = val.length()-1;
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<num; j++)
            {
                string tmp = v[i];
                tmp+=val[j+1];
                v.push_back(tmp);
            }
            v[i]+=val[0];
        }
        return;
    }
};