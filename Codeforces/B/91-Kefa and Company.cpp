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
    ll n, d; cin >> n >> d;
    vector<pair<ll, ll>>ar(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> ar[i].first;
        cin >> ar[i].second;
    }
    sortv(ar);
    vector<ll>ans;
    ll a = 0, b = 1;
    ll temp = ar[0].second;
    while (b < n)
    {
        if (ar[b].first - ar[a].first < d)
        {
            temp += ar[b].second;
            b++;
        }
        else {
            ans.push_back(temp);
            while (ar[b].first - ar[a].first >= d)
            {
                temp -= ar[a].second;
                a++;
            }
            temp += ar[b].second;
            b++;
        }
    }
    ans.push_back(temp);
    ll mx = INT_MIN;
    for (ll i = 0; i < ans.size(); i++)
    {
        mx = max(ans[i], mx);
    }
    cout << mx << endl;
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
