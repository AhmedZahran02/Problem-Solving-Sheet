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
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '1')
        {
            ans += s[i];
        }
    }
    int j = 0;
    while (ans[j] == '0')
    {
        cout << ans[j];
        j++;
    }
    for (int i = 0; i < s.length() - ans.length(); i++)
    {
        cout << '1';
    }
    while (j < ans.length()) {
        cout << ans[j];
        j++;
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
