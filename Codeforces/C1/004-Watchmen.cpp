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

//nCr
ll ncr(ll n, ll r) {
    if (r > n - r) r = n - r;
    ll ans = 1;
    ll i;

    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void solve() {
    ll n; cin >> n;
    map<ll, ll>x;
    map<ll, ll>y;
    map<pair<ll, ll>, ll>vis;
    for (ll i = 0; i < n; i++)
    {
        ll a, b; cin >> a >> b;
        x[a]++;
        y[b]++;
        vis[{a, b}] ++;
    }
    ll ans = 0;
    for (auto i : x)
    {
        if (i.second > 1)
        {
            ans += ncr(i.second, 2);
        }
    }
    for (auto i : y)
    {
        if (i.second > 1)
        {
            ans += ncr(i.second, 2);
        }
    }
    for (auto i : vis)
    {
        if (i.second > 1)
        {
            ans -= ncr(i.second, 2);
        }
    }
    cout << ans << endl;
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
