class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return INT_MAX;
        if (i == 0 && j == 0)
            return grid[0][0];
        if (dp[i][j] != -1)return dp[i][j];
        dp[i][j] = grid[i][j] + min(solve(grid, i - 1, j, dp), solve(grid, i, j - 1, dp));
        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(201, vector<int>(201, -1));
        return solve(grid, grid.size() - 1, grid[0].size() - 1, dp);
    }
};