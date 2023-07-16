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

bool check(vector<ll>& ar) {
    map<ll, bool> mp;
    for (ll i = 0; i < ar.size(); i++)
    {
        if (mp[ar[i]])
        {
            return false;
        }
        mp[ar[i]] = 1;
    }
    return true;
}

void print(vector<ll>& ar) {
    for (ll i = 0; i < ar.size(); i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}

void solve() {
    ll n; cin >> n;
    vector<ll>ar;
    for (ll i = 0; i < n; i++)
    {
        ar.push_back(i);
    }
    vector<ll>ar3(n);
    for (ll i = 0; i < n; i++)
    {
        ar3[i] = (ar[i] + ar[i]) % n;
    }
    if (check(ar3))
    {
        print(ar);
        print(ar);
        print(ar3);
    }
    else {
        cout << -1 << endl;
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
