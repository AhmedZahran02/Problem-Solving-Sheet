// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile() freopen("Zahran", "r", stdin)
#define sortv(vec) sort(vec.begin(),vec.end()) //sort vector
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

set<ll> primefactors(ll n) {
    set<ll> x;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            x.insert(i);
        }
    }
    if (n != 1)
    {
        x.insert(n);
    }
    return x;
}

void solve() {
    ll n;
    cin >> n;
    set<ll> x = primefactors(n);
    ll ans = 1;
    for (auto i = x.begin(); i != x.end(); i++)
    {
        ans *= *i;
    }
    cout << ans << endl;
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