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
    string s, t;
    while (getline(cin, s) && getline(cin, t))
    {
        vector<ll>ar1;
        vector<ll>ar2;
        stringstream ss(s);
        string temp;
        while (getline(ss, temp, ' ')) {
            try {
                ar1.push_back(stoll(temp));
            }
            catch (...) {

            }
        }
        stringstream ss2(t);
        while (getline(ss2, temp, ' ')) {
            try {
                ar2.push_back(stoll(temp));
            }
            catch (...) {

            }
        }
        for (ll i = 0; i < ar2.size(); i++)
        {
            ll val = ar2[i];
            ll ans = ar1[0];
            for (ll j = 1; j < ar1.size(); j++)
            {
                ans *= ar2[i];
                ans += ar1[j];
            }
            if (i == ar2.size() - 1)
            {
                cout << ans;
                continue;
            }
            cout << ans << " ";
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
