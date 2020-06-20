class Solution {
public:
    bool isValid(string s) {
        int len = s.size();
        if(len==0) return true;
        char stack[len];
        int top = -1;
        for(auto c : s)
        {
            if(top<0)
            {
                stack[++top]=c;
                continue;
            }
            char pop = stack[top];
            switch (pop)
            {
            case '(':
                if(c==')')
                {
                    top--;
                }
                else
                {
                    stack[++top]=c;
                }
                break;
            case '[':
                if(c==']')
                {
                    top--;
                }
                else
                {
                    stack[++top]=c;
                }
                break;
            case '{':
                if(c=='}')
                {
                    top--;
                }
                else
                {
                    stack[++top]=c;
                }
                break;
            default:
                stack[++top]=c;
                break;
            }
        }
        return (top<0);
    }
};