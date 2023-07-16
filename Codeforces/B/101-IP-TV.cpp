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

class Disjointset {
private:
    ll size;
    ll* sz;
    ll* id;
    ll numofcomp;
    ll* numofedges;

public:
    Disjointset(ll size) {
        if (size > 0)
        {
            this->size = size;
            this->numofcomp = size;
            sz = new ll[size];
            id = new ll[size];
            numofedges = new ll[size];

            for (ll i = 0; i < size; i++)
            {
                id[i] = i;
                sz[i] = 1;
                numofedges[i] = 0;
            }
        }
        else {
            this->size = 0;
            this->numofcomp = 0;
            sz = new ll[0];
            id = new ll[0];
        }
    }

    ll find(ll p) {
        ll trav = p;
        while (trav != id[trav])
        {
            trav = id[trav];
        }

        while (p != trav) {
            ll next = id[p];
            id[p] = trav;
            p = next;
        }

        return trav;
    }

    bool connected(ll p, ll q) {
        return find(p) == find(q);
    }

    ll componentsizeofnode(ll p) {
        return sz[find(p)];
    }

    ll componentsize(ll i) {
        return sz[i];
    }

    ll edgesize(ll i) {
        return numofedges[i];
    }

    ll getsize() {
        return size;
    }

    ll getnumofcomponents() {
        return numofcomp;
    }

    void unify(ll p, ll q) {
        ll root1 = find(p);
        ll root2 = find(q);

        if (root1 == root2)
        {
            numofedges[root1]++;
            return;
        }

        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            sz[root1] = 0;
            id[root1] = root2;
            numofedges[root2] += numofedges[root1] + 1;
            numofedges[root1] = 0;
        }
        else {
            sz[root1] += sz[root2];
            sz[root2] = 0;
            id[root2] = root1;
            numofedges[root1] += numofedges[root2] + 1;
            numofedges[root2] = 0;
        }
        numofcomp--;
    }
};

void solve() {
    ll t; cin >> t;
    for (ll z = 0; z < t; z++)
    {
        ll n; cin >> n;
        ll q; cin >> q;
        ll counter = 1;
        map<string, ll>mp;
        vector<pair<ll, pair<ll, ll>>>edges;
        for (ll i = 0; i < q; i++)
        {
            string s1, s2; cin >> s1 >> s2;
            ll city1, city2;
            ll cost; cin >> cost;
            if (mp[s1])
            {
                city1 = mp[s1] - 1;
            }
            else {
                mp[s1] = counter;
                counter++;
                city1 = mp[s1] - 1;
            }
            if (mp[s2])
            {
                city2 = mp[s2] - 1;
            }
            else {
                mp[s2] = counter;
                counter++;
                city2 = mp[s2] - 1;
            }
            edges.push_back({ cost, {city1,city2} });
        }
        sortv(edges);
        Disjointset ds(n);
        ll ans = 0;
        for (ll i = 0; i < edges.size(); i++)
        {
            if (ds.getnumofcomponents() == 1)
            {
                break;
            }
            else {
                if (ds.find(edges[i].second.first) != ds.find(edges[i].second.second))
                {
                    ds.unify(edges[i].second.first, edges[i].second.second);
                    ans += edges[i].first;
                }
            }
        }
        cout << ans << endl;
        if (z != t-1)
        {
            cout << endl;
        }
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
