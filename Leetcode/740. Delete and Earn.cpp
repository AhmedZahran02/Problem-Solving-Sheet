//leet code
#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
typedef long long ll;
typedef unsigned long long ull;

class Solution {
public:

    ll recurse(ll i, vector<int>& ar, vector<ll>& dp, map<ll, ll>& mp) {
        if (i == ar.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        ll n = i;
        ll m = i;
        for (int j = i + 1; j < ar.size(); j++)
        {
            if (ar[j] == ar[i])
            {
                n++;
                m++;
            }
            if (ar[j] == ar[i] + 1)
            {
                m++;
            }
        }
        ll op1 = mp[ar[i]] * ar[i] + recurse(m + 1, ar, dp, mp);
        ll op2 = recurse(n + 1, ar, dp, mp);
        dp[i] = max(op1, op2);
        return dp[i];
    }

    int deleteAndEarn(vector<int>& nums) {
        vector<ll>dp(nums.size() + 1, -1);
        map<ll, ll>mp;
        for (ll i : nums) mp[i]++;
        sortv(nums);
        ll res = recurse(0, nums, dp, mp);
        return res;
    }
};