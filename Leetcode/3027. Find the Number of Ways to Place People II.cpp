#define all(v) v.begin(), v.end()

bool sortbyfirst(const vector<int> &a, const vector<int> &b)
{
    if (a[0] != b[0])
    {
        return a[0] < b[0];
    }
    return a[1] > b[1];
}

class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        sort(all(points), sortbyfirst);
        int ans = 0;
        for (int i = 0; i < points.size(); i++)
        {
            int lowestDip = INT_MIN;
            for (int j = i + 1; j < points.size(); j++)
            {
                // y2 <= y1
                if (points[j][1] <= points[i][1])
                {
                    // check boundary validation
                    if (points[j][1] <= lowestDip)
                    {
                        // skip
                    }
                    else
                    {
                        ans++;
                        lowestDip = max(lowestDip, points[j][1]);
                    }
                }
            }
        }
        return ans;
    }
};