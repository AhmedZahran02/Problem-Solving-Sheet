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

// sort by second pair
bool sortbysec(const pair<ll, ll>& a, const pair<ll, ll>& b)
{
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void solve() {
    ll n; cin >> n;
    vector<pair<ll, ll>>ar1(n);
    vector<pair<ll, ll>>ar2(n);
    for (ll i = 0; i < n; i++)
    {
        ar1[i].first = i;
        ar2[i].first = i;
        cin >> ar1[i].second >> ar2[i].second;
    }
    sort(all(ar1), sortbysec);
    sort(all(ar2), sortbysec);
    vector<bool>ans1(n, 0);
    vector<bool>ans2(n, 0);
    for (ll i = 0; i < n / 2; i++)
    {
        ans1[i] = 1;
        ans2[i] = 1;
    }
    ll itr1 = 0, itr2 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (ar1[itr1].second <= ar2[itr2].second)
        {
            ans1[ar1[itr1].first] = 1;
            itr1++;
        }
        else {
            ans2[ar2[itr2].first] = 1;
            itr2++;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        cout << ans1[i];
    }
    cout << endl;
    for (ll i = 0; i < n; i++)
    {
        cout << ans2[i];
    }
    cout << endl;
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
