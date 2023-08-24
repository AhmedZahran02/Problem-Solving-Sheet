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

//powmod
ll PowMod(ll b, ll e, ll M) {
    if (!e)
    {
        return 1;
    }
    ll p = PowMod(((__int128)b * b) % M, e / 2, M);
    return (e % 2) ? ((__int128)p * b) % M : p % M;
}

void solve() {
    ll MOD = 1e9 + 7;
    ll a, b, n; cin >> a >> b >> n;
    ll m = a == b ? MOD : abs(a - b);
    cout << gcd(abs(a - b),(PowMod(a, n, m) + PowMod(b, n, m)) % m) % MOD << endl;
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
