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
    ll n, m; cin >> n >> m;
    vector<bool>cat(n);
    vector<bool>vis(n, 0);
    vector<vector<ll>>gp(n);
    for (ll i = 0; i < n; i++)
    {
        bool x; cin >> x;
        cat[i] = x;
    }
    for (ll i = 0; i < n - 1; i++)
    {
        ll x, y; cin >> x >> y;
        x--; y--;
        gp[x].push_back(y);
        gp[y].push_back(x);
    }
    ll ans = 0;
    queue<pair<ll, ll>>q;
    q.push({ 0,0 });
    while (!q.empty())
    {
        ll node = q.front().first;
        ll Ncat = q.front().second;
        q.pop();
        vis[node] = 1;
        if (cat[node])
        {
            Ncat++;
        }
        else {
            Ncat = 0;
        }
        if (Ncat > m)
        {
            continue;
        }
        bool done = 0;
        for (ll i = 0; i < gp[node].size(); i++)
        {
            if (!vis[gp[node][i]])
            {
                q.push({ gp[node][i] ,Ncat });
                done = 1;
            }
        }
        if (!done)
        {
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
