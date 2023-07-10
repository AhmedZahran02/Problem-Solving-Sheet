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
    ll l, h, r;
    vector<ll>ar(10001, 0);
    while (cin >> l >> h >> r) {
        for (ll i = l; i < r; ++i) {
            ar[i] = max(ar[i], h);
        }
    }
    // process array
    ll num = -1;
    ll start = 1;
    ll i = 1;
    while (ar[i] == 0)
    {
        i++;
    }
    ll save = i;
    for (; i < ar.size(); i++)
    {
        if (ar[i] != num)
        {
            if (num != -1)
            {
                if (start == save)
                {
                    cout << start << " ";
                }
                cout << num << " " << i << " ";
            }
            num = ar[i];
            start = i;
        }
    }
    cout << 0 << endl;
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    ll t = 1;
    //    cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
