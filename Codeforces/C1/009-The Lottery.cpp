// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define all(v) v.begin(),v.end()
#define sortv(vec) sort(all(vec)) //sort vector
#define getdiff(v1,v2,dist) set_difference(all(v1), all(v2),back_inserter(dist)); // search for v1 in v2 if v is empty without order else use search(v1,v2)
typedef long long ll;
typedef unsigned long long ull;
const double pi = 3.14159265358979323846;

using namespace std;

//greatest common divisor
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//least common multiple
ll lcm(ll a, ll b)
{
    if (a == 1 && b == 1)
    {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}

void solve() {
    ll n, m;
    while (cin >> n >> m)
    {
        ll ans = 0;
        vector<ll>nums(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> nums[i];
        }
        ll cnt = 0;

        for (ll i = 1; i < ((ll)1 << m); i++) {
            ll divisors = 0;
            ll div = 1;

            for (ll j = 0; j < m; j++) {
                if (i & ((ll)1 << j)) {
                    divisors++;
                    div = lcm(div, nums[j]);
                }
            }

            ll sign = (divisors % 2 == 0) ? -1 : 1;
            cnt += sign * (n / div);
        }

        cout << n - cnt << endl;
    }
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    ll t = 1;
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
