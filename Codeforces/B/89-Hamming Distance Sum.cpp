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

void solve() {
    string a, b; cin >> a >> b;
    ll sum = 0;
    vector<ll>ones(b.length() + 1, 0);
    vector<ll>zeros(b.length() + 1, 0);

    for (ll i = 1; i <= b.length(); i++)
    {
        if (b[i - 1] == '0')
        {
            zeros[i] = zeros[i - 1] + 1;
            ones[i] = ones[i - 1];
        }
        else {
            ones[i] = ones[i - 1] + 1;
            zeros[i] = zeros[i - 1];
        }
    }

    for (ll i = 0; i < a.length(); i++)
    {
        if (a[i] == '1')
        {
            sum += zeros[b.length() - a.length() + i + 1] - zeros[i];
        }
        else {
            sum += ones[b.length() - a.length() + i + 1] - ones[i];
        }
    }

    cout << sum << endl;
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
