// Made by AOZPROGRAMMING - All Rights Reserved :)
#define all(v) v.begin(), v.end()

class Solution
{
public:
    string clearDigits(string s)
    {
        stack<char> st;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
            {
                if (st.size())
                    st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }
        string ans = "";
        while (st.size())
        {
            ans += st.top();
            st.pop();
        }
        reverse(all(ans));
        return ans;
    }
};