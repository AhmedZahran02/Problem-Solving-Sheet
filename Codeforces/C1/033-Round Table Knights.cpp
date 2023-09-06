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

set<ll> factors(ll n) {
    set<ll> x;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            x.insert(i);
            x.insert(n / i);
        }
    }
    return x;
}

bool check(ll start, ll i, ll jump, vector<ll>& ar) {
    if (i == start)
    {
        return true;
    }
    if (ar[i] == 0)
    {
        return false;
    }
    else {
        return check(start, (i + jump) % ar.size(), jump, ar);
    }
}

void solve() {
    ll n; cin >> n;
    set<ll>s = factors(n);
    vector<ll>zeros;
    vector<ll>ar(n);
    ll zero = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i];
        if (ar[i] == 0)
        {
            zero++;
        }
        else {
            if (zero != 0)
            {
                zeros.push_back(zero);
                zero = 0;
            }
        }
    }
    if (zero != 0)
    {
        zeros.push_back(zero);
    }
    sortv(zeros);
    ll mx = 0;
    if (zeros.size() > 0)
    {
        mx = zeros[zeros.size() - 1];
    }
    vector<ll>maybe;
    for (auto itr : s)
    {
        if (itr <= n / 3 && itr > mx)
        {
            maybe.push_back(itr);
        }
    }
    if (maybe.size() == 0)
    {
        cout << "NO" << endl;
        return;
    }
    else {
        // logic
        for (ll i = 0; i < maybe.size(); i++)
        {
            for (ll j = 0; j < maybe[i]; j++)
            {
                if (ar[j] == 1)
                {
                    if (check(j, (j + maybe[i]) % ar.size(), maybe[i], ar))
                    {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }
        cout << "NO" << endl;
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
