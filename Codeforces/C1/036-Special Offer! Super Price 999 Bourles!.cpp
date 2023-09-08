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

//long long int faster pow func
ll fastpow(ll b, ll e) {
    if (!e)
    {
        return 1;
    }
    if (e & 1)
    {
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}

bool test(ll num, ll index, ll k) {
    if (index == to_string(num).length())
    {
        return true;
    }
    return num - ((num / fastpow(10ll, index) - 1) * fastpow(10ll, index) + fastpow(10, index) - 1) <= k;
}

ll bs(ll start, ll end, ll num, ll k) {
    while (start < end - 1)
    {
        ll mid = start + (end - start) / 2;
        if (test(num, mid, k))
        {
            start = mid;
        }
        else {
            end = mid - 1;
        }
    }
    if (test(num, end, k))
    {
        if (end == to_string(num).length())
        {
            if (test(num, start, k))
            {
                return start;
            }
        }
        return end;
    }
    else
    {
        return start;
    }
}

void solve() {
    ll p, d; cin >> p >> d;
    ll start = 1;
    while (fastpow(10, start) - 1 == p % fastpow(10, start))
    {
        start++;
    }
    ll index = bs(start, to_string(p).length(), p, d);
    if (index == to_string(p).length())
    {
        cout << p << endl;
    }
    else if (p - ((p / fastpow(10ll, index) - 1) * fastpow(10ll, index) + fastpow(10, index) - 1) <= d)
    {
        cout << (p / fastpow(10ll, index) - 1) * fastpow(10ll, index) + fastpow(10, index) - 1 << endl;
    }
    else {
        cout << p << endl;
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
