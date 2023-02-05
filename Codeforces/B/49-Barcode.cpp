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

ll recurse(ll i, ll n, ll x, ll y, vector<ll>& ar, bool state, ll statecount, vector<vector<vector<ll>>>& dp) {
    if (i == ar.size())
    {
        if (statecount<x || statecount > y)
        {
            return INT_MAX;
        }
        return 0;
    }

    if (dp[i][statecount][state] != -1)
    {
        return dp[i][statecount][state];
    }

    //white state 0
    ll op1 = INT_MAX;
    if (statecount == 0 || (statecount + 1 <= y && state == 0) || (state == 1 && statecount >= x))
    {
        if (state == 1)
        {
            op1 = (n - ar[i]) + recurse(i + 1, n, x, y, ar, 0, 1, dp);
        }
        else {
            op1 = (n - ar[i]) + recurse(i + 1, n, x, y, ar, 0, statecount + 1, dp);
        }
    }
    //black state 1
    ll op2 = INT_MAX;
    if (statecount == 0 || (statecount + 1 <= y && state == 1) || (state == 0 && statecount >= x))
    {
        if (state == 0)
        {
            op2 = ar[i] + recurse(i + 1, n, x, y, ar, 1, 1, dp);
        }
        else {
            op2 = ar[i] + recurse(i + 1, n, x, y, ar, 1, statecount + 1, dp);
        }
    }

    return dp[i][statecount][state] = min(op1, op2);
}

void solve() {
    ll n, m, x, y; cin >> n >> m >> x >> y;
    vector<ll>ar(m, 0);
    vector<vector<vector<ll>>>dp(m, vector<vector<ll>>(y + 1, vector<ll>(2, -1)));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '#')
            {
                ar[j]++;
            }
        }
    }
    cout << recurse(0, n, x, y, ar, 0, 0, dp) << endl;
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
