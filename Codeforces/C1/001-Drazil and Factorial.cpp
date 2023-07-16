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
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll>ar(10, 0);
    for (ll i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case '2':
            ar[2]++;
            break;
        case '3':
            ar[3]++;
            break;
        case '4':
            ar[2] += 2;
            ar[3]++;
            break;
        case '5':
            ar[5]++;
            break;
        case '6':
            ar[3]++;
            ar[5]++;
            break;
        case '7':
            ar[7]++;
            break;
        case '8':
            ar[7]++;
            ar[2] += 3;
            break;
        case '9':
            ar[7]++;
            ar[2]++;
            ar[3] += 2;
            break;
        default:
            break;
        }
    }
    for (ll i = 9; i >= 0; i--)
    {
        for (ll j = 0; j < ar[i]; j++)
        {
            cout << i;
        }
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
