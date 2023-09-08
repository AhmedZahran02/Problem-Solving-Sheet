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
    vector<vector<pair<ll, pair<ll, ll>>>> ar(n + 2);
    ll level = 1;
    for (ll i = 0; i < m; i++)
    {
        ll l, r, x; cin >> l >> r >> x;
        if (x == l)
        {
            ar[l + 1].push_back({ level,{x,0 } });
            ar[r + 1].push_back({ level,{x,1} });
        }
        else if (x == r)
        {
            ar[l].push_back({ level,{x,0 } });
            ar[r].push_back({ level,{x,1} });
        }
        else if (x > l && x < r)
        {
            ar[l].push_back({ level,{x,0 } });
            ar[x].push_back({ level,{x,1 } });
            ar[x + 1].push_back({ level,{x,0 } });
            ar[r + 1].push_back({ level,{x,1} });
        }
        else {
            ar[l].push_back({ level,{x,0 } });
            ar[r + 1].push_back({ level,{x,1} });
        }
        level++;
    }
    set<pair<ll, ll>> st;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < ar[i].size(); j++)
        {
            if (ar[i][j].second.second == 0)
            {
                st.insert({ ar[i][j].first,ar[i][j].second.first });
            }
            else {
                st.erase(st.find({ ar[i][j].first,ar[i][j].second.first }));
            }
        }
        if (st.size() != 0)
        {
            cout << (*st.begin()).second << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
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
