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

map<ll, ll> dp;

ll getNumOfDivisors(ll num) {
    if (dp[num] != 0)
    {
        return dp[num];
    }
    else {
        ll ans = 0;
        for (ll i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                ans += 2;
            }
        }
        if (sqrt(num) == int(sqrt(num)))
        {
            ans--;
        }
        return dp[num] = ans;
    }
}

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    ll sum = 0;
    for (ll i = 1; i <= a; i++)
    {
        for (ll j = 1; j <= b; j++)
        {
            for (ll k = 1; k <= c; k++)
            {
                sum += getNumOfDivisors(i * j * k);
                sum = sum % 1073741824;
            }
        }
    }
    cout << sum << endl;
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
