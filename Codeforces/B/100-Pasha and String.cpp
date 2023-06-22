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
    string s; cin >> s;
    ll m; cin >> m;
    vector<ll>ar(s.length() + 2, 0);
    for (ll i = 0; i < m; i++)
    {
        ll x; cin >> x;
        ar[x] += 1; ar[s.length() - x + 2] -= 1;
    }
    for (ll i = 1; i < ar.size() / 2; i++)
    {
        ar[i] += ar[i - 1];
        if (ar[i] % 2 != 0)
        {
            swap(s[i - 1], s[s.length() - i]);
        }
    }
    cout << s << endl;
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
