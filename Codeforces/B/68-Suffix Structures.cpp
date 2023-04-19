// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<unordered_map>
//#include <chrono>

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
    vector<int> vis(26, 0);
    if (t.length() > s.length())
    {
        cout << "need tree" << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        vis[s[i] - 'a'] ++;
    }
    for (int i = 0; i < t.length(); i++)
    {

        if (vis[t[i] - 'a'] > 0)
        {
            vis[t[i] - 'a']--;
        }
        else {
            cout << "need tree" << endl;
            return;
        }
    }
    if (s.length() == t.length())
    {
        cout << "array" << endl;
        return;
    }
    int ind = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (ind < t.length() && s[i] == t[ind])
        {
            ind++;
        }
    }
    if (ind == t.length())
    {
        cout << "automaton" << endl;
        return;
    }
    cout << "both" << endl;
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
