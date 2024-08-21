#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
typedef long long ll;
typedef unsigned long long ull;

map<ll,ll> primefactors(ll n) {
    map<ll,ll> x;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            x[i]++;
        }
    }
    if (n != 1)
    {
        x[n]++;
    }
    return x;
}

class Solution {
public:
    int minSteps(int n) {
        map<ll,ll> primeFactors = primefactors(n);
        ll result = 0;
        for (auto i : primeFactors)
        {
            result += i.first * i.second;
        }
        return result;
    }
};