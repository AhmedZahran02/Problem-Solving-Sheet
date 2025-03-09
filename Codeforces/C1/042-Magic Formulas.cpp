// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll xor1ToM(ll m) {
    if (m % 4 == 0) return m;
    if (m % 4 == 1) return 1;
    if (m % 4 == 2) return m + 1;
    return 0;
}

void solve() {
    ll n; cin >> n;
    ll number = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x; cin >> x;
        number ^= x;
    }
    ll seq = 0;
    for (ll i = 1; i <= n; i++) {
        ll numOfBlocks = n / i;
        seq ^= (numOfBlocks % 2) * xor1ToM(i - 1);
        seq ^= xor1ToM(n % i);
    }
    cout << (number ^ seq) << endl;
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    int t = 1;
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
