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

// sort by second pair modified
bool sortbysecahhh(const pair<pair<ll, ll>, ll>& a, const pair<pair<ll, ll>, ll>& b)
{
    if (a.second == b.second) {
        return a.first.second > b.first.second;
    }
    return a.second > b.second;
}

void solve() {
    ll n; cin >> n;
    vector<pair<pair<ll, ll>, ll>>ar(n);
    for (ll i = 0; i < n; i++)
    {
        ar[i].first.first = i + 1;
        cin >> ar[i].first.second >> ar[i].second;
    }
    sort(all(ar), sortbysecahhh);
    ll k; cin >> k;
    vector<pair<ll, ll>>tables(k);
    vector<bool>vis(k);
    for (ll i = 0; i < k; i++)
    {
        cin >> tables[i].first;
        tables[i].second = i;
    }
    sortv(tables);
    ll cnt = 0;
    ll sum = 0;
    vector<pair<ll, ll>>out;
    for (ll i = 0; i < n; i++)
    {
        ll index = lower_bound(all(tables), make_pair(ar[i].first.second, (ll)0)) - tables.begin();
        for (ll j = index; j < k; j++)
        {
            if (!vis[j])
            {
                cnt++;
                sum += ar[i].second;
                out.push_back({ ar[i].first.first,tables[j].second + 1 });
                vis[j] = 1;
                break;
            }
        }
    }
    cout << cnt << " " << sum << endl;
    for (ll i = 0; i < out.size(); i++)
    {
        cout << out[i].first << " " << out[i].second << endl;
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
