class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ')
        {
            i++;
        }
        string s2 = s.substr(i);
        int ans = 0;
        try
        {
            ans = stoi(s2);
        }
        catch (const std::exception&)
        {
            if (s2[0] == '-' && s2[1] >= '0' && s2[1] <= '9')
            {
                return INT_MIN;
            }
            else if ((s2[0] >= '0' && s2[0] <= '9') || (s2[0] == '+' && s2[1] >= '0' && s2[1] <= '9'))
            {
                return INT_MAX;
            }
            else
            {
                return 0;
            }
        }
        return ans;
    }
};