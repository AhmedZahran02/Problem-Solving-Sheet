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
    ll n; cin >> n;
    ll cnt = 1;
    vector<ll> ar(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
        cin >> ar[i];
    }
    stack<ll>s;
    s.push(ar[0]);
    for (ll i = 0; i < n; i++)
    {
        while (!s.empty() && ar[i] < s.top())
        {
            s.pop();
        }
        if (!s.empty() && s.top() == ar[i])
        {
            continue;
        }
        s.push(ar[i]);
        cnt++;
    }
    cout << cnt << endl;
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    int t = 1;
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
