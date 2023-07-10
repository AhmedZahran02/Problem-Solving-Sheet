// Made by AOZPROGRAMMING - All Rights Reserved :)
// i wanna sleep so bad

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
    vector<ll> ar(n);
    ll minind = 0;
    ll maxind = 0;
    ll cnt = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
        if (abs(ar[i] - ar[minind]) <= 1 && abs(ar[i] - ar[maxind]) <= 1)
        {
            if (ar[i] >= ar[maxind])
            {
                maxind = i;
            }
            if (ar[i] <= ar[minind])
            {
                minind = i;
            }
            cnt++;
        }
        else {
            if (ar[i] > ar[i-1]) {
                cnt = i - minind;
                minind = i - 1;
                maxind = i;
            }
            else {
                cnt = i - maxind;
                maxind = i - 1;
                minind = i;
            }
        }
        ans = max(ans, cnt);
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
