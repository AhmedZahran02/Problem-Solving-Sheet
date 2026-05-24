class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        for (auto &v : mat)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] != v[(i + k) % v.size()])
                    return false;
            }
        }
        return true;
    }
};