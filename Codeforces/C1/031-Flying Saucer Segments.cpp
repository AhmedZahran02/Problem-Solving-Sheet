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

ll PowMod(ll b, ll e, ll M) {
    ll res = 1;
    b = b % M;
    if (b == 0) return 0;
    while (e > 0)
    {
        if (e & 1)
            res = (res * b) % M;
        e = e >> 1;
        b = (b * b) % M;
    }
    return (res % M + M) % M;
}

void solve() {
    ll n, m; cin >> n >> m;
    ll ans = 2;
    ll val = 0;
    cout << ((ans + 3ll * (PowMod(3ll, (n - 1ll), m) - 1ll))%m+m)%m << endl;
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
