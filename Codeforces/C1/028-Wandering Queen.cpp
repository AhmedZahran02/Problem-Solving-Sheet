// Made by AOZPROGRAMMING - All Rights Reserved :)
//TLE
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

ll reverse(ll dir) {
    switch (dir)
    {
    case 0:
        return 2;
    case 1:
        return 3;
    case 2:
        return 0;
    case 3:
        return 1;
    case 4:
        return 6;
    case 5:
        return 7;
    case 6:
        return 4;
    case 7:
        return 5;
    }
    return 0;
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<char>>ar(n, vector<char>(m, '.'));
    vector<vector<ll>>dp(n, vector<ll>(m, INT_MAX));
    vector<vector<vector<ll>>>vis(n, vector<vector<ll>>(m, vector<ll>(8, -1)));
    ll starti;
    ll startj;
    ll endi;
    ll endj;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> ar[i][j];
            if (ar[i][j] == 'S')
            {
                starti = i;
                startj = j;
            }
            if (ar[i][j] == 'F')
            {
                endi = i;
                endj = j;
            }
        }
    }
    queue<pair<pair<ll, ll>, pair<ll, ll>>>q;
    q.push({ {starti,startj},{-1,1} });
    vector<ll>x = { 0,1,0,-1,-1,1,1,-1 };
    vector<ll>y = { 1,0,-1,0,1,1,-1,-1 };
    ll ans = INT_MAX;
    while (!q.empty())
    {
        ll i = q.front().first.first;
        ll j = q.front().first.second;
        ll dir = q.front().second.first;
        ll val = q.front().second.second;
        q.pop();
        if (i == starti && j == startj)
        {
            for (ll z = 0; z < 8; z++)
            {
                vis[i][j][z] = 0;
            }
        }
        if (ar[i][j] == 'F')
        {
            if (val > ans)
            {
                break;
            }
            ans = val;
        }
        for (ll z = 0; z < x.size(); z++)
        {
            if (i + x[z] < n && i + x[z] >= 0 && j + y[z] < m && j + y[z] >= 0 && ar[i + x[z]][j + y[z]] != 'X') {
                ll cost = val;
                if (dir != -1 && z != dir)
                {
                    cost++;
                }
                if (vis[i + x[z]][j + y[z]][reverse(z)] != -1 && vis[i + x[z]][j + y[z]][reverse(z)] < cost)
                {
                    continue;
                }
                q.push({ {i + x[z],j + y[z]},{z,cost} });
                vis[i + x[z]][j + y[z]][reverse(z)] = cost;
            }
        }
    }
    if (ans == INT_MAX)
    {
        ans = -1;
    }
    cout << ans << endl;
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    ll t = 1;
    cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
