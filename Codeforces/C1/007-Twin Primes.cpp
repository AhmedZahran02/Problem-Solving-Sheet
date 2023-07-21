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
    vector<bool>primes(20000001, 1);
    primes[0] = 0;
    primes[1] = 0;
    // preprocessing
    for (ll i = 2; i * i <= 20000000; i++)
    {
        if (primes[i])
        {
            for (ll j = 2 * i; j <= 20000000; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    vector<pair<ll, ll>>ans;
    ll prime1 = 2;
    for (ll i = 3; i < primes.size(); i++)
    {
        if (primes[i])
        {
            if (i - prime1 == 2)
            {
                ans.push_back({ prime1,i });
            }
            prime1 = i;
        }
    }
    ll n;
    while (cin >> n)
    {
        cout << '(' << ans[n - 1].first << ", " << ans[n - 1].second << ')' << endl;
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
