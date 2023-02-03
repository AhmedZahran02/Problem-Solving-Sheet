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

void solve() {
    double vp, vd, t, f, c; cin >> vp >> vd >> t >> f >> c;

    double pl = 0;
    double dl = 0;
    pl += vp * t;

    ll ans = 0;

    while (pl<c && vd> vp)
    {
        double dist = (pl / ((vd / vp) - 1));
        pl += dist;
        dl += dist;
        if (c - pl > 0.0000001)
        {
            ans++;
        }

        double drt = pl / vd + f;
        dl = 0;
        pl += drt * vp;
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
