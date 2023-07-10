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
    ll a, x, y; cin >> a >> x >> y;
    if (y % a == 0 || y <= 0)
    {
        cout << -1 << endl;
        return;
    }
    ll row = y / a;
    if (row == 0 || row % 2 == 1)
    {
        if (true)
        {

        }
        if (2 * x<a && 2 * x > -a)
        {
            if (row == 0)
            {
                cout << 1 << endl;
                return;
            }
            cout << floor((row - 1) / 2.0) * 2 + ceil((row - 1) / 2.0) + 2 << endl;
        }
        else {
            cout << -1 << endl;
            return;
        }
    }
    else {
        if (x == 0 || !(x<a && x > -a))
        {
            cout << -1 << endl;
            return;
        }
        else {
            if (x > 0)
            {
                cout << floor((row - 1) / 2.0) * 2 + ceil((row - 1) / 2.0) + 3 << endl;
            }
            else {
                cout << floor((row - 1) / 2.0) * 2 + ceil((row - 1) / 2.0) + 2 << endl;
            }
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
