// Made by AOZPROGRAMMING - All Rights Reserved :)
// might get tl
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
    string s, t; cin >> s >> t;
    map<ll, ll>mp;
    for (ll i = 0; i < t.length(); i++)
    {
        mp[t[i]]++;
    }
    ll yay = 0, whoops = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        if (mp[s[i]] > 0)
        {
            yay++;
            mp[s[i]]--;
            s[i] = ' ';
        }
    }
    for (ll i = 0; i < s.length(); i++)
    {
        if (s[i]==' ')
        {
            continue;
        }
        if (islower(s[i]))
        {
            if (mp[toupper(s[i])] > 0)
            {
                whoops++;
                mp[toupper(s[i])]--;
            }
        }
        else {
            if (mp[tolower(s[i])] > 0)
            {
                whoops++;
                mp[tolower(s[i])]--;
            }
        }
    }
    cout << yay << " " << whoops << endl;
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
