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
    ll n, r, avg; cin >> n >> r >> avg;
    avg *= n;
    vector<pair<ll, ll>>ar(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i].second >> ar[i].first;
        sum += ar[i].second;
    }
    sortv(ar);
    ll i = 0;
    ll ans = 0;
    while (sum < avg)
    {
        if (ar[i].second < r)
        {
            ll needed = min(r - ar[i].second, avg - sum);
            ar[i].second+= needed;
            sum+=needed;
            ans += ar[i].first * needed;
            if (sum >= avg)
            {
                break;
            }
        }
        i++;
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
