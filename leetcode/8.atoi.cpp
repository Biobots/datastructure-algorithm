class Solution {
public:
    int myAtoi(string str) {
        unsigned int size = str.size();
        if (size == 0 || (str[0] != '+' && str[0] != ' ' && str[0] != '-' && str[0] > '9' && str[0] < '0')) return 0;
        long rst = 0;
        unsigned int ptr = 0;
        bool flag = 1;
        while (ptr < size)
        {
            if (str[ptr] == ' ')
            {
                ptr++;
                continue;
            }
            else
            {
                break;
            }
        }
        if (str[ptr] == '-')
        {
            flag = 0; ptr++;
        }
        else if (str[ptr] == '+') ptr++;
        int count = 0;
        while (ptr < size)
        {
            if (str[ptr] <= '9' && str[ptr] >= '0')
            {
                rst *= 10;
                if (rst == 0 && str[ptr] == '0')
                {
                    ptr++;
                    continue;
                }
                rst += (int)(str[ptr] - '0');
                count++;
                if (count > 10) return flag ? INT_MAX : INT_MIN;
                ptr++;
            }
            else
            {
                break;
            }
        }
        rst = flag ? rst : -rst;
        return (int)(rst > INT_MIN ? (rst < INT_MAX ? rst : INT_MAX) : INT_MIN);
    }
};