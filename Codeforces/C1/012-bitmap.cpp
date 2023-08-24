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

vector<ll>idx = { 1,-1,0,0 };
vector<ll>idy = { 0, 0,1,-1 };

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> ar(n, vector<ll>(m));
    queue<pair<ll, ll>>list;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char c; cin >> c;
            if (c == '1')
            {
                ar[i][j] = 0;
                list.push({ i,j });
            }
            else {
                ar[i][j] = INT_MAX;
            }
        }
    }
    while (!list.empty())
    {
        pair<ll, ll> node = list.front();
        ll i = node.first;
        ll j = node.second;
        list.pop();
        for (ll k = 0; k < 4; k++)
        {
            if (i + idx[k] < ar.size() && j + idy[k] < ar[0].size() && i + idx[k] >= 0 && j + idy[k] >= 0)
            {
                if (ar[i][j] + 1 < ar[i + idx[k]][j + idy[k]])
                {
                    ar[i + idx[k]][j + idy[k]] = ar[i][j] + 1;
                    list.push({ i + idx[k], j + idy[k] });
                }
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }
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
