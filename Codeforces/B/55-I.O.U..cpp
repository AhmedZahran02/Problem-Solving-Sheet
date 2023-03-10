// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<unordered_map>
//#include <chrono>

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
    ll n, m; cin >> n >> m;
    vector<vector<ll>>ar(n, vector<ll>(n, 0));
    for (ll i = 0; i < m; i++)
    {
        ll x, y, c; cin >> x >> y >> c;
        ar[x - 1][y - 1] = c;
    }

    //test
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < n; j++)
    //    {
    //        cout << ar[i][j] <<" ";
    //    }
    //    cout << endl;
    //}

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x = 0;
        ll y = 0;
        for (int j = 0; j < n; j++)
        {
            x += ar[i][j];
            y += ar[j][i];
        }
        if (y >= x)
        {
            ans += abs(x - y);
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
