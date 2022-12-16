class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        bool d = 0;
        for (int i = 0; i < strs[0].size(); i++)
        {
            char c = ' ';
            for (int j = 0; j < strs.size(); j++)
            {
                if (c == ' ')
                {
                    c = strs[0][i];
                }
                if (c != strs[j][i])
                {
                    d = 1;
                    break;
                }
            }
            if (d == 1)
            {
                break;
            }
            ans += c;
        }
        return ans;
    }
};