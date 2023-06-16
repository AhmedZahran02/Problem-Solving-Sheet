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

bool isbeautiful(string x) {
    for (int i = 2; i <= 9; i++)
    {
        if (x.find(i + '0') != string::npos)
        {
            return false;
        }
    }
    ll l = -1; ll r = -1;
    if (x.find('1') == string::npos)
    {
        return true;
    }
    else {
        l = x.find('1');
    }
    if (x.rfind('1') == string::npos)
    {
        return true;
    }
    else {
        r = x.rfind('1');
    }
    if (l != r)
    {
        return false;
    }
    return true;
}

void solve() {
    ll n; cin >> n;
    ull zeroscnt = 0;
    string nonbeautifulstr = "1";
    bool done = 0;
    bool zero = 0;
    string x;
    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        if (x == "0")
        {
            zero = 1;
        }
        if (x == "1")
        {
            continue;
        }
        if (!done && !zero) {
            if (isbeautiful(x))
            {
                zeroscnt += (ll)x.length() - 1ll;
            }
            else {
                nonbeautifulstr = x;
                done = 1;
            }
            continue;
        }
        zeroscnt += (ll)x.length() - 1ll;
    }
    if (zero)
    {
        cout << 0 << endl;
        return;
    }
    cout << nonbeautifulstr;
    for (ll i = 0; i < zeroscnt; i++)
    {
        cout << 0;
    }
    cout << endl;
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
