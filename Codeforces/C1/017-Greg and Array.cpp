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

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll>ar(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    vector<pair<pair<ll, ll>, ll>>op(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> op[i].first.first >> op[i].first.second >> op[i].second;
    }
    vector<ll>freq(m + 2);
    for (ll i = 0; i < k; i++)
    {
        ll x, y; cin >> x >> y;
        freq[x]++;
        freq[y + 1]--;
    }
    for (ll i = 1; i < freq.size(); i++)
    {
        freq[i] += freq[i - 1];
    }
    vector<ll>app(n + 2, 0);
    for (ll i = 0; i < m; i++)
    {
        app[op[i].first.first] += op[i].second * freq[i + 1];
        app[op[i].first.second + 1] -= op[i].second * freq[i + 1];
    }
    for (ll i = 1; i < app.size(); i++)
    {
        app[i] += app[i - 1];
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << ar[i] + app[i] << " ";
    }
    cout << endl;
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
