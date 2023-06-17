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
    string n; cin >> n;
    int64_t bitmask = 0;
    ll index = 0;
    for (ll i = (ll)(n.length() - 1); i >= 0; i--)
    {
        if (n[i] == '4')
        {
            bitmask |= ((ll)0 << index);
        }
        else {
            bitmask |= ((ll)1 << index);
        }
        index++;
    }
    ll ans = 0;
    ans += pow(2, n.length()) - 2;
    cout << ans + bitmask + 1 << endl;
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
