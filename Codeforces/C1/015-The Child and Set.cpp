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

ll getLowBit(ll num) {
    return (num & -num);
}

void solve() {
    ll sum, limit; cin >> sum >> limit;
    vector<pair<ll, ll>>ar(limit + 1);
    ar[0].first = 0;
    ar[0].second = INT_MIN;
    for (ll i = 1; i <= limit; i++)
    {
        ar[i].first = i;
        ar[i].second = getLowBit(i);
    }
    sort(all(ar), sortbysec);
    ll val = 0;
    ll start = 1;
    ll end = 1;
    while (val < sum)
    {
        if (end == ar.size())
        {
            cout << -1 << endl;
            return;
        }
        val += ar[end].second;
        end++;
    }
    while (val > sum)
    {
        val -= ar[start].second;
        start++;
    }
    ll start2 = 1;
    while (val != sum)
    {
        val += ar[start2].second;
        start2++;
    }
    cout << end - start + start2 - 1 << endl;
    for (ll i = start; i < end; i++)
    {
        cout << ar[i].first << " ";
    }
    for (ll i = 1; i < start2; i++)
    {
        cout << ar[i].first << " ";
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
