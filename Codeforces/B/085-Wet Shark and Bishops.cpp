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

//nCr
ll ncr(ll n, ll r) {
    if (r > n - r) r = n - r;
    ll ans = 1;
    ll i;

    for (i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void solve() {
    ll n; cin >> n;
    vector<ll>freq(2001, 0);
    vector<ll>reversefreq(2001, 0);
    for (ll i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        ll index1 = x - y;
        if (index1 < 0)
        {
            index1 = -index1;
            index1 += 1000;
        }
        freq[index1]++;

        x = 1000 - x;
        ll index2 = x - y;
        if (index2 < 0)
        {
            index2 = -index2;
            index2 += 1000;
        }
        reversefreq[index2]++;
    }
    ll sum = 0;
    for (ll i = 0; i < freq.size(); i++)
    {
        if (freq[i] >= 2)
        {
            sum += ncr(freq[i], 2);
        }
        if (reversefreq[i] >= 2)
        {
            sum += ncr(reversefreq[i], 2);
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
