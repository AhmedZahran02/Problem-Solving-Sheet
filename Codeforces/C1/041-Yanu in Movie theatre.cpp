// Made by AOZPROGRAMMING - All Rights Reserved :)

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve()
{
    ll n, m;
    while (cin >> n >> m && !(!m && !n))
    {
        if (n > m)
            cout << fixed << setprecision(6) << double(0) << endl;
        else
            cout << fixed << setprecision(6) << double(m - n + 1) / (m + 1) << endl;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}