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
    ll m, n;

    while (cin >> m >> n && !(m == 1 && n == 1))
    {
        string s = "";
        ll currm = 1, currn = 1;
        ll leftm = 0, leftn = 1;
        ll rightm = 1, rightn = 0;
        while (!(currm == m && currn == n))
        {
            if (currm * n <= currn * m)//right
            {
                s += "R";
                leftm = currm;
                leftn = currn;
                currm = currm + rightm;
                currn = currn + rightn;
            }
            else //left
            {
                s += "L";
                rightm = currm;
                rightn = currn;
                currm = currm + leftm;
                currn = currn + leftn;

            }
        }
        cout << s << endl;
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
