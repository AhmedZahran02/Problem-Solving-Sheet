typedef long long ll;
class Solution
{
public:
    int makeTheIntegerZero(ll num1, ll num2)
    {
        for (ll i = 0; i <= 60; i++)
        {
            ll x = num1 - i * num2;
            if (x < 0)
                break;
            if (__builtin_popcountll(x) <= i && i <= x)
                return i;
        }
        return -1;
    }
};