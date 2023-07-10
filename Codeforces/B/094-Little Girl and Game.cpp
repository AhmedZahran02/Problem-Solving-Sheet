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
    string s; cin >> s;
    vector<ll>ar(26, 0);
    for (ll i = 0; i < s.length(); i++)
    {
        ar[s[i] - 'a']++;
    }
    ll odds = 0, evens = 0;
    for (ll i = 0; i < 26; i++)
    {
        if (ar[i] == 0)
        {
            continue;
        }
        if (ar[i] % 2 == 0)
        {
            evens++;
        }
        else {
            odds++;
        }
    }
    if (odds == 1 || odds == 0)
    {
        cout << "First" << endl;
        return;
    }
    if ((odds + 2 * evens) % 2 != 0)
    {
        cout << "First" << endl;
    }
    else {
        cout << "Second" << endl;
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
