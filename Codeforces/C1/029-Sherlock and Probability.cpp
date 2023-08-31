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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll>ar(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        char c; c = s[i - 1];
        if (c == '1')
        {
            ar[i] = ar[i - 1] + 1;
        }
        else {
            ar[i] = ar[i - 1];
        }
    }
    ll ans = ar[ar.size() - 1];
    for (ll i = 0; i < ar.size() - 1; i++)
    {
        if (s[i] == '1') {
            ll j = min((ll)(ar.size() - 1), i + k + 1ll);
            ans += 2 * (ar[j] - ar[i + 1]);
        }
    }
    ll dem = n * n;
    ll val = gcd(ans, dem);
    cout << ans / val << "/" << dem / val << endl;
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    ll t = 1;
    cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
