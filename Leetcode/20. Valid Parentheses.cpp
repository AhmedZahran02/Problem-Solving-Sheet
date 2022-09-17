class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                if (s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    return false;
                }
                st.push(s[i]);
            }
            else
            {
                if (s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    if (s[i] == ')')
                    {
                        if (st.top() != '(')
                        {
                            return false;
                        }
                        else
                        {
                            st.pop();
                        }
                    }
                    if (s[i] == '}')
                    {
                        if (st.top() != '{')
                        {
                            return false;
                        }
                        else
                        {
                            st.pop();
                        }
                    }
                    if (s[i] == ']')
                    {
                        if (st.top() != '[')
                        {
                            return false;
                        }
                        else
                        {
                            st.pop();
                        }
                    }
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        if (!st.empty())
        {
            return false;
        }
        return true;
    }
};