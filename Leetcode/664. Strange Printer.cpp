class Solution {
public:
   vector<vector<int>>dp;
   int recurse(int i, int j, string& s) {
       if (i > j)return 0;
       if (i == j)return 1;
       if (dp[i][j] != -1)return dp[i][j];
       int ans = 0;
       ans = 1 + recurse(i, j - 1, s);
       for (int k = i; k < j; k++) {
           if (s[k] == s[j])ans = min(ans, (recurse(i, k, s) + recurse(k + 1, j - 1, s)));
       }
       return dp[i][j] = ans;
   }
   int strangePrinter(string s) {
       dp.resize(s.size() + 1, vector<int>(s.size() + 1, -1));
       return recurse(0, s.size() - 1, s);
   }
};