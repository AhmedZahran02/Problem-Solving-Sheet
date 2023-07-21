// Made by AOZPROGRAMMING - All Rights Reserved :)
// yes the code is clowny as it should be :) 
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

void primefactorsheh(ll n,map <ll, ll>& mp) {
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            mp[i]++;
        }
    }
    if (n != 1)
    {
        mp[n]++;
    }
}

void primefactorsheh2(ll n, map <ll, ll>& mp) {
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            mp[i]--;
        }
    }
    if (n != 1)
    {
        mp[n]--;
    }
}

void solve() {
    ll a, b; cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    map<ll, ll>mp;
    primefactorsheh(a, mp);
    primefactorsheh2(b, mp);
    ll ans = 0;
    for (auto i : mp)
    {
        if (i.first > 5 && i.second != 0)
        {
            cout << -1 << endl;
            return;
        }
        else {
            ans += abs(i.second);
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
