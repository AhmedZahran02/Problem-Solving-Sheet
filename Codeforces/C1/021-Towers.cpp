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
    ll n, k; cin >> n >> k;
    vector<pair<ll, ll>>ar(n);
    for (ll i = 0; i < n; i++)
    {
        ar[i].first = i + 1;
        cin >> ar[i].second;
    }
    sort(all(ar), sortbysec);
    ll cnt = 0;
    vector<pair<ll, ll>>ans;
    while (k && ar[0].second < ar[ar.size() - 1].second)
    {
        ar[ar.size() - 1].second--;
        ar[0].second++;
        cnt++;
        k--;
        ans.push_back({ ar[ar.size() - 1].first,ar[0].first });
        ll j = 0;
        while (j + 1 < ar.size() && ar[j + 1].second < ar[j].second)
        {
            swap(ar[j], ar[j + 1]);
            j++;
        }
        j = (ll)ar.size() - 1;
        while (j - 1 >= 0 && ar[j - 1].second > ar[j].second)
        {
            swap(ar[j - 1], ar[j]);
            j--;
        }
    }
    cout << ar[ar.size() - 1].second - ar[0].second << " " << cnt << endl;
    for (ll i = 0; i < cnt; i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
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
