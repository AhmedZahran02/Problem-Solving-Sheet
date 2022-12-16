
class Solution {
public:

    int solve(int n, vector<int>& dp) {
        if (n == 1 || n == 0)return dp[n] = 1;
        if (dp[n] != -1)return dp[n];
        dp[n] = 0;
        for (int i = 0; i < n; i++) {
            dp[n] += solve(i, dp) * solve(n - i - 1, dp);
        }
        return dp[n];
    }

    int numTrees(int n) {
        vector<int> dp(20, -1);
        return solve(n, dp);
    }
};