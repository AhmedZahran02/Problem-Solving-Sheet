class Solution {
public:
    string convert(string s, int numRows) {
    vector<string>ar(numRows,"");
    int j = 0;
    bool down = 1;
    for (int i = 0; i < s.length(); i++)
    {
        ar[j] += s[i];
        if (down)
        {
            j++;
            if (j== numRows)
            {
                down = 0;
                if (numRows==1)
                {
                    j -= 1;
                }
                else
                {
                    j -= 2;
                } 
            }
        }
        else
        {
            j--; 
            if (j == -1)
            {
                down = 1;
                if (numRows == 1)
                {
                    j = 0;
                }
                else
                {
                    j = 1;
                }
            }
        }
    }
    string ans = "";
    for (int i = 0; i < numRows; i++)
    {
        ans += ar[i];
    }
    return ans;
}
};