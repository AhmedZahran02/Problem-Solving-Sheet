class Solution
{
private:
    int recurse(int start, vector<int> &arr, int d, vector<int> &dp)
    {
        if (dp[start] != -1)
            return dp[start];
        int ans = 1;

        for (int i = 1; start + i < arr.size() && i <= d && arr[start + i] < arr[start]; i++)
            ans = max(ans, 1 + recurse(start + i, arr, d, dp));

        for (int i = 1; start - i >= 0 && i <= d && arr[start - i] < arr[start]; i++)
            ans = max(ans, 1 + recurse(start - i, arr, d, dp));

        return dp[start] = ans;
    }

public:
    int maxJumps(vector<int> &arr, int d)
    {
        int ans = 0;
        vector<int> dp(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++)
            ans = max(ans, recurse(i, arr, d, dp));
        return ans;
    }
};