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
    ll n, k; cin >> n >> k;
    ll mx = ceil(n / 2.0) * ceil(n / 2.0) + floor(n / 2.0) * floor(n / 2.0);
    if (k > mx)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    bool land = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            land = 0;
        }
        else {
            land = 1;
        }
        for (int j = 0; j < n; j++)
        {
            if (k)
            {
                if (!land)
                {
                    cout << 'L';
                    land = 1;
                    k--;
                }
                else {
                    cout << 'S';
                    land = 0;
                }

            }
            else {
                cout << 'S';
            }
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
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
