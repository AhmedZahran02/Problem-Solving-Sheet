class Solution {
public:
    int recurse(vector<int>& piles, vector<vector<vector<int>>>& dp, int index, int M, bool playerTurn) {
        if (index == piles.size()) {
            return 0;
        }
        if (dp[index][M][int(playerTurn)] != -1) return dp[index][M][int(playerTurn)];
        int ans = playerTurn ? INT_MIN : INT_MAX;
        int valueTaken = 0;
        int currIndex = index;
        for (int x = 1; (x <= 2 * M) && (x <= (piles.size() - index)); x++) {
            valueTaken += piles[currIndex];
            currIndex++;
            if (playerTurn) {
                ans = max(ans, valueTaken + recurse(piles, dp, currIndex, max(M, x), !playerTurn));
            }
            else {
                ans = min(ans, recurse(piles, dp, currIndex, max(M, x), !playerTurn));
            }
        }
        return dp[index][M][int(playerTurn)] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(200, vector<vector<int>>(200, vector<int>(2, -1)));
        return recurse(piles,dp, 0, 1, 1);
    }
};