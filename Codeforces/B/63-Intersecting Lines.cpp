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
    ll n; cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    for (ll i = 0; i < n; i++)
    {
        double slope1, slope2, c1, c2;
        bool vertical1 = 0, vertical2 = 0; double xint1, xint2;
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x2 - x1 == 0)
        {
            vertical1 = 1; xint1 = x1;
        }
        else {
            slope1 = (double)(y2 - y1) / (x2 - x1);
            c1 = y2 - slope1 * x2;
        }
        cin >> x1 >> y1 >> x2 >> y2;
        if (x2 - x1 == 0)
        {
            vertical2 = 1; xint2 = x1;
        }
        else {
            slope2 = (double)(y2 - y1) / (x2 - x1);
            c2 = y2 - slope2 * x2;

        }
        if (vertical1 && vertical2)
        {
            if (abs(xint1 - xint2) <= 0.0000000000000001)
            {
                cout << "LINE" << endl;
            }
            else {
                cout << "NONE" << endl;
            }
        }
        else if (vertical1 || vertical2)
        {
            cout << "POINT ";
            if (vertical1)
            {
                cout << fixed << setprecision(2) << xint1 << " ";
                cout << fixed << setprecision(2) << slope2 * xint1 + c2 << endl;
            }
            else {
                cout << fixed << setprecision(2) << xint2 << " ";
                cout << fixed << setprecision(2) << slope1 * xint2 + c1 << endl;
            }
        }
        else if (abs(slope1 - slope2) <= 0.0000000000000001)
        {
            if (abs(c1 - c2) <= 0.0000000000000001)
            {
                cout << "LINE" << endl;
            }
            else {
                cout << "NONE" << endl;
            }
        }
        else
        {
            cout << "POINT ";
            double x = (c2 - c1) / (slope1 - slope2);
            cout << fixed << setprecision(2) << x << " ";
            cout << fixed << setprecision(2) << slope1 * x + c1 << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
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
