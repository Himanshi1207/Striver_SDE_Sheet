#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        int itr = 0, n = s.size();
        while (s[itr] == ' ')
            itr++;
        int sign = 1;
        if (itr < n && s[itr] == '+' || s[itr] == '-')
        {
            sign = (s[itr++] == '+') ? 1 : -1;
        }
        int num = 0;
        while (itr < n && s[itr] >= '0' && s[itr] <= '9')
        {
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[itr] - '0' > 7))
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            num = num * 10 + (s[itr++] - '0');
        }

        return sign * num;
    }
};