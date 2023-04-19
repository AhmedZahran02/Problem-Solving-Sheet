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
    string s; cin >> s;
    if (s.length() < 26)
    {
        cout << -1 << endl;
        return;
    }
    vector<ll>vis(26, -1);
    ll start = 0;
    ll end = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
        {
        }
        else if (vis[s[i] - 'A'] == -1)
        {
            vis[s[i] - 'A'] = i;
        }
        else {
            int j = start;
            start = vis[s[i] - 'A'] + 1;
            for (; j <= vis[s[i] - 'A']; j++)
            {
                if (s[j] != '?')
                {
                    vis[s[j] - 'A'] = -1;
                }
            }
            vis[s[i] - 'A'] = i;
        }
        end++;
        if (end - start == 26)
        {
            break;
        }
    }
    if (end - start != 26)
    {
        cout << -1 << endl;
        return;
    }
    int val = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '?')
        {
            continue;
        }
        if (i < start || i >= end)
        {
            s[i] = 'A';
        }
        else {
            while (vis[val] != -1)val++;
            s[i] = 'A' + val;
            vis[val] = 0;
        }
    }
    cout << s << endl;
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
