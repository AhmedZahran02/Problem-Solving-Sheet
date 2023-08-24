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

set<ll> s;

void combinations(vector<ll>& ar, ll i, ll LCM, ll cnt) {
    if (cnt == 4)
    {
        s.insert(LCM);
        return;
    }
    if (i >= ar.size())
    {
        return;
    }
    combinations(ar, i + 1, lcm(LCM, ar[i]), cnt + 1);
    combinations(ar, i + 1, LCM, cnt);
}

void solve() {
    ll n, t;
    while (cin >> n >> t && !(n == 0 && t == 0))
    {
        vector<ll>ar(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        vector<ll>temp;
        s.clear();
        combinations(ar, 0, 1, 0);
        for (ll k = 0; k < t; k++)
        {
            ll mn = INT_MIN;
            ll mx = INT_MAX;
            ll q; cin >> q;
            for (auto itr : s)
            {
                mn = max(mn, itr * (q / itr));
                mx = min(mx, itr * (ll)ceil((double)q / (double)itr));
            }
            cout << mn << " " << mx << endl;
        }
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
