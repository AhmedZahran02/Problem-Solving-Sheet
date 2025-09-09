typedef long long ll;

// long long int faster pow func
ll fastpow(ll b, ll e)
{
    if (!e)
    {
        return 1;
    }
    if (e & 1)
    {
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}

class Solution
{
public:
    long long minOperations(vector<vector<int>> &queries)
    {
        // number of operations for a number = log4(num) + 1
        // separate using 4^i to subsets => those < 4^i need i op
        ll numOfOp = 0;
        for (auto query : queries)
        {
            ll start = query[0];
            ll end = query[1];
            ll log4Start = ll(log(start) / log(4)) + 1;
            ll ans = 0;
            ll value = fastpow(4, log4Start);
            ll lastValue = value / 4;
            for (int i = log4Start;; i++)
            {
                ans += (min((value - 1), end) - max(start, lastValue) + 1) * i;
                if ((value - 1) > end)
                {
                    break;
                }
                value *= 4;
                lastValue *= 4;
            }
            numOfOp += ceil(ans / 2.0);
        }
        return numOfOp;
    }
};