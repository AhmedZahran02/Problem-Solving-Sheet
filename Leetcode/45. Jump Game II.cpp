#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
typedef long long ll;
typedef unsigned long long ull;

class Solution {
public:
    ll recurse(int i, vector<int>& ar, vector<ll>& dp) {
        if (i >= ar.size())
        {
            return INT_MAX;
        }
        if (i == ar.size() - 1)
        {
            return 0;
        }
        if (ar[i] == 0)
        {
            return INT_MAX;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }

        ll done = INT_MAX;
        for (int j = 1; j <= ar[i]; j++)
        {
            ll mn = 1 + recurse(i + j, ar, dp);
            if (mn < INT_MAX)
            {
                done = min(mn, done);
            }
        }
        return dp[i] = done;
    }

    int jump(vector<int>& nums) {
        vector<ll>dp(100000 + 1, -1);
        return recurse(0, nums, dp);
    }
};