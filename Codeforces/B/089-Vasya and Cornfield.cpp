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

void case1(ll n, ll d, ll x, ll y) {
    if (x <= d)
    {
        ll y1 = -x + d;
        ll y2 = x + d;
        if (y >= y1 && y <= y2)
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else if (x <= n - d)
    {
        ll y1 = x - d;
        ll y2 = x + d;
        if (y >= y1 && y <= y2)
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else
    {
        ll y1 = x - d;
        ll y2 = -x + 2 * n - d;
        if (y >= y1 && y <= y2)
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

void case2(ll n, ll d, ll x, ll y) {
    if (x <= d)
    {
        ll y1 = -x + d;
        ll y2 = x + d;
        if (y >= y1 && y <= y2)
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else
    {
        ll y1 = x - d;
        ll y2 = -x + 2 * n - d;
        if (y >= y1 && y <= y2)
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

void case3(ll n, ll d, ll x, ll y) {
    if (x <= n - d)
    {
        ll y1 = -x + d;
        ll y2 = x + d;
        if (y >= y1 && y <= y2)
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else if (x <= d)
    {
        ll y1 = -x + d;
        ll y2 = -x + 2 * n - d;
        if (y >= y1 && y <= y2)
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else
    {
        ll y1 = x - d;
        ll y2 = -x + 2 * n - d;
        if (y >= y1 && y <= y2)
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}

void solve() {
    ll n, d; cin >> n >> d;
    ll m; cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y; cin >> x >> y;
        if (x > n || y > n || x < 0 || y < 0)
        {
            cout << "NO" << endl;
        }
        else {
            // you can just say y > the 2 eqs of the bottom and < the 2 eqs of the top
            if (d == n - d)
            {
                case2(n, d, x, y);
            }
            else if (d < n - d)
            {
                case1(n, d, x, y);
            }
            else {
                case3(n, d, x, y);
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
