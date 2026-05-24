class Solution
{
private:
    int diff(string &query, string &dict)
    {
        int ans = 0;
        for (int i = 0; i < query.size(); i++)
        {
            ans += int(query[i] != dict[i]);
            if (ans > 2)
                break;
        }
        return ans;
    }
    bool check(string &query, vector<string> &dictionary)
    {
        for (auto dict : dictionary)
        {
            if (diff(query, dict) <= 2)
                return true;
        }
        return false;
    }

public:
    vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
    {
        vector<string> ans;
        for (auto query : queries)
        {
            if (check(query, dictionary))
                ans.push_back(query);
        }
        return ans;
    }
};