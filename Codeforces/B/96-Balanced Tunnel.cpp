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
    ll n; cin >> n;
    vector<ll>in(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    vector<ll>out(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> out[i];
    }
    ll i = n - 1, j = n - 1;
    ll ans = 0;
    map<ll, bool>vis;
    while (i >= 0 && j >= 0)
    {
        while (j >= 0 && vis[out[j]])
        {
            j--;
        }
        if (j < 0)
        {
            break;
        }
        if (in[i] == out[j])
        {
            i--; j--;
        }
        else {
            vis[in[i]] = 1;
            i--;
            ans++;
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
