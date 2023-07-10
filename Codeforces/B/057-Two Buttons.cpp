// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<unordered_map>
//#include <chrono>

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

ll recurse(ll n, ll m, map<pair<ll, ll>, ll>& dp) {
    if (n >= m)
    {
        return n - m;
    }

    if (n <= 0)
    {
        return INT_MAX;
    }

    if (dp[{n, m}] != 0)
    {
        return dp[{n, m}];
    }

    dp[{n, m}] = INT_MAX;

    return dp[{n, m}] = 1 + min(recurse(n - 1, m, dp), recurse(2 * n, m, dp));
}

void solve() {
    ll n, m; cin >> n >> m;
    map<pair<ll, ll>, ll>dp;
    cout << recurse(n, m, dp) << endl;
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

////bfs solution 
//void solve() {
//    ll n, m; cin >> n >> m;
//    ll ans = 0;
//    queue<pair<ll, ll>> q;
//    vector<ll>vis(max(2 * m + 1, n + 1), 0);
//    q.push({ n , 0 });
//    while (!q.empty())
//    {
//        pair<ll, ll> x = q.front();
//        q.pop();
//
//        if (vis[x.first])
//        {
//            continue;
//        }
//
//        vis[x.first] = 1;
//
//        if (x.first == m)
//        {
//            ans += x.second;
//            break;
//        }
//
//        if (x.first < m)
//        {
//            q.push({ 2 * x.first ,x.second + 1 });
//        }
//        if (x.first > 1)
//        {
//            q.push({ x.first - 1, x.second + 1 });
//        }
//    }
//    cout << ans << endl;
//}
