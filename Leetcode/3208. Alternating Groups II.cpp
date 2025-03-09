class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        vector<int> part;
        int count = 1;
        for (int i = 1; i < colors.size(); i++)
        {
            if (colors[i] != colors[i - 1])
                count++;
            else
            {
                part.push_back(count);
                count = 1;
            }
        }
        if (part.size() == 0 && colors[0] != colors[colors.size() - 1])
            return colors.size();
        if (colors.size() > 0 && colors[0] != colors[colors.size() - 1])
            part[0] += count;
        else
            part.push_back(count);

        int ans = 0;
        for (int i = 0; i < part.size(); i++)
        {
            if (part[i] >= k)
            {
                ans += part[i] - k + 1;
            }
        }
        return ans;
    }
};