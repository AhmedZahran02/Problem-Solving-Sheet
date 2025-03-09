// Made by AOZPROGRAMMING - All Rights Reserved :)

#include <bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile()                      \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define all(v) v.begin(), v.end()
#define sortv(vec) sort(all(vec)) // sort vector
typedef long long ll;
typedef unsigned long long ull;
const double pi = 3.14159265358979323846;

using namespace std;

void solve()
{
    ll n, b;
    cin >> n >> b;

    map<string, vector<pair<ll, ll>>> mp;
    vector<string> types;

    for (ll i = 0; i < n; i++)
    {
        string type, name;
        ll p, q;
        cin >> type >> name >> p >> q;
        mp[type].push_back({p, q});
    }

    for (const auto &entry : mp)
    {
        types.push_back(entry.first);
    }

    for (auto &type : mp)
    {
        sort(all(type.second));
        vector<pair<ll, ll>> filtered;
        ll maxQuality = 0;

        for (auto pq : type.second)
        {
            if (pq.second > maxQuality)
            {
                filtered.push_back(pq);
                maxQuality = pq.second;
            }
        }
        mp[type.first] = filtered;
    }

    ll left = 0, right = 1e18, result = 0;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll totalCost = 0;
        bool possible = true;

        for (const string &type : types)
        {
            ll minCost = LLONG_MAX;
            for (auto pq : mp[type])
            {
                if (pq.second >= mid)
                {
                    minCost = min(minCost, pq.first);
                }
            }
            if (minCost == LLONG_MAX)
            {
                possible = false;
                break;
            }
            totalCost += minCost;
            if (totalCost > b)
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << result << endl;
}

int main()
{
    fast1();
    fast2();
    // infile();
    //-------------------------------------------
    int t = 1;
    cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}