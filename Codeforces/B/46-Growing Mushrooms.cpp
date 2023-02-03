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

// sort by second pair
bool sortbysec(const pair<ll, double>& a, const pair<ll, double>& b)
{
    if (abs(a.second - b.second) < 0.0000001) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

void solve() {
    double n, t1, t2, k; cin >> n >> t1 >> t2 >> k;
    vector<pair<ll, double>>ar(n);
    for (ll i = 1; i <= n; i++)
    {
        double x, y; cin >> x >> y;
        ar[i - 1] = { i,max(t1 * x * ((100 - k) / 100.0) + t2 * y,t1 * y * ((100 - k) / 100.0) + t2 * x) };
    }
    sort(all(ar), sortbysec);
    for (ll i = 0; i < n; i++)
    {
        cout << ar[i].first << " " << fixed << setprecision(2) << ar[i].second << endl;
    }
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    int t = 1;
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
