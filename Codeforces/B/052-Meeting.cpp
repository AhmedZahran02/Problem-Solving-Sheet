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

bool euclid(pair<ll, ll> p1, pair<ll, ll> p2, ll d) {
    if ((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second) <= (d * d))
    {
        return true;
    }
    return false;
}

void solve() {
    ll x, y, x2, y2; cin >> x >> y >> x2 >> y2;

    ll xbigger = max(x, x2);
    ll xsmaller = min(x, x2);
    ll ybigger = max(y, y2);
    ll ysmaller = min(y, y2);

    vector<pair<ll, ll>>tablepoints;
    for (ll i = ysmaller + 1; i < ybigger; i++)
    {
        tablepoints.push_back({ xsmaller,i });
    }
    for (ll i = ysmaller + 1; i < ybigger; i++)
    {
        tablepoints.push_back({ xbigger,i });
    }
    for (ll i = xsmaller; i <= xbigger; i++)
    {
        tablepoints.push_back({ i,ysmaller });
    }
    for (ll i = xsmaller; i <= xbigger; i++)
    {
        tablepoints.push_back({ i,ybigger });
    }

    ll q; cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll x, y, r; cin >> x >> y >> r;
        for (ll i = 0; i < tablepoints.size(); i++)
        {
            if (euclid(tablepoints[i], { x,y }, r))
            {
                tablepoints.erase(tablepoints.begin() + i);
                i--;
            }
        }
    }
    cout << tablepoints.size() << endl;
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
