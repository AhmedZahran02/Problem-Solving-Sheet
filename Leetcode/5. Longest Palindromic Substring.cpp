string longestPalindrome(string s) {
    string ans="";
    //odd
    for (int i = 0; i < s.length(); i++)
    {
        deque<char>ar;
        int l = i-1; int r = i+1;
        ar.push_back(s[i]);
        while (r < s.length() && l >= 0)
        {
            if (s[l] == s[r])
            {
                ar.push_back(s[l]);
                ar.push_front(s[l]);
            }
            else
            {
                break;
            }
            l--; r++;
        }
        string temp = "";
        for (int i = 0; i < ar.size(); i++)
        {
            temp += ar[i];
        }
        if (temp.length()>ans.length())
        {
            ans = temp;
        }
    }
    //even
    for (int i = 0; i < s.length(); i++)
    {
        deque<char>ar;
        int l = i; int r = i+1;
        while (r < s.length() && l >= 0)
        {
            if (s[l] == s[r])
            {
                ar.push_back(s[l]);
                ar.push_front(s[l]);
            }
            else
            {
                break;
            }
            l--; r++;
        }
        string temp = "";
        for (int i = 0; i < ar.size(); i++)
        {
            temp += ar[i];
        }
        if (temp.length() > ans.length())
        {
            ans = temp;
        }
    }
    return ans;
}