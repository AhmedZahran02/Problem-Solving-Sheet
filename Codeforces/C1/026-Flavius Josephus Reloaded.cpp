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
    if (!e)
    {
        return 1;
    }
    ll p = PowMod((b * b) % M, e / 2, M);
    return (e % 2) ? (p * b) % M : p % M;
}

void solve() {
    ll n, a, b;
    while (cin >> n && n != 0)
    {
        map<ll, int>ar;
        cin >> a >> b;
        ar[0]++;
        ll ans = 0;
        ll x = 0;
        while (true)
        {
            x = (a % n * PowMod(x, 2, n) % n + b % n) % n;
            ar[x]++;
            if (ar[x] == 3)
            {
                cout << n - ans << endl;
                break;
            }
            else if (ar[x] == 2)
            {
                ans++;
            }
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
