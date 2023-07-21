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
    queue<ll> q1;
    queue<ll> q2;
    ll n1; cin >> n1;
    for (ll i = 0; i < n1; i++)
    {
        ll x; cin >> x;
        q1.push(x);
    }
    ll n2; cin >> n2;
    for (ll i = 0; i < n2; i++)
    {
        ll x; cin >> x;
        q2.push(x);
    }
    ll cnt = 0;
    while (!q1.empty() && !q2.empty())
    {
        if (cnt > 400)
        {
            cout << -1 << endl;
            return;
        }
        if (q1.front() > q2.front())
        {
            q1.push(q2.front());
            q1.push(q1.front());
            q1.pop();
            q2.pop();
        }
        else {
            q2.push(q1.front());
            q2.push(q2.front());
            q2.pop();
            q1.pop();
        }
        cnt++;
    }
    ll ans = 1;
    if (q1.empty())
    {
        ans = 2;
    }
    cout << cnt << " " << ans << endl;
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
