class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    map<char, int>mp;
    int mx = 0;
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp[s[i]]<i + 1 && mp[s[i]] > j)
        {
            mx = max(i - j, mx);
            j = mp[s[i]];
        }
        mp[s[i]] = i + 1;
    }
    if (mx == 0) {
        mx = s.length();
    }
    mx = max(mx, int(s.length()) - j);
    return mx;
}
};