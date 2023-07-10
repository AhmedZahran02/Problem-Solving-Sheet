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
    ll n, k; cin >> n >> k;
    bool zero = 0;
    vector<ll>pos;
    vector<ll>neg;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x > 0)
        {
            pos.push_back(x);
        }
        else if (x < 0) {
            neg.push_back(x);
        }
        else {
            zero = 1;
        }
    }
    for (int i = 0; i < neg.size(); i++)
    {
        if (k)
        {
            neg[i] = -neg[i];
            k--;
        }
        else {
            break;
        }
    }
    if (k % 2 == 0 || zero)
    {
        // do sum
        ll sum = 0;
        for (ll i = 0; i < pos.size(); i++)
        {
            sum += pos[i];
        }
        for (ll i = 0; i < neg.size(); i++)
        {
            sum += neg[i];
        }
        cout << sum << endl;
    }
    else {
        if (pos.size() && neg.size() && neg[neg.size() - 1] > pos[0])
        {
            pos[0] = -pos[0];
        }
        else if (pos.size() && neg.size() && neg[neg.size() - 1] < pos[0])
        {
            neg[neg.size() - 1] = -neg[neg.size() - 1];
        }
        else if (pos.size())
        {
            pos[0] = -pos[0];
        }
        else {
            neg[neg.size() - 1] = -neg[neg.size() - 1];
        }
        //do sum
        ll sum = 0;
        for (ll i = 0; i < pos.size(); i++)
        {
            sum += pos[i];
        }
        for (ll i = 0; i < neg.size(); i++)
        {
            sum += neg[i];
        }
        cout << sum << endl;
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
