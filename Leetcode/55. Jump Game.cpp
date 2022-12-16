#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
typedef long long ll;
typedef unsigned long long ull;

class Solution {
public:

    bool recurse(int i, vector<int>& ar, vector<int>& dp) {
        if (i >= ar.size())
        {
            return dp[i] = 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        if (i == ar.size() - 1)
        {
            return dp[i] = 1;
        }
        if (ar[i] == 0)
        {
            return dp[i] = 0;
        }

        bool done = 0;
        for (int j = 1; j <= ar[i]; j++)
        {
            done |= recurse(i + j, ar, dp);
            if (done) {
                break;
            }
        }
        return dp[i] = done;
    }

    bool canJump(vector<int>& nums) {
        vector<int>dp(100000 + 1, -1);
        return recurse(0, nums, dp);
    }
};