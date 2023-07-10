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
    while (t)
    {
        ll n, m; cin >> n >> m;
        // first best
        Disjointset ds(n);
        vector<pair<ll, pair<ll, ll>>>edges;

        for (ll i = 0; i < m; i++)
        {
            ll x, y, z; cin >> x >> y >> z;
            x--; y--;
            edges.push_back(make_pair(z, make_pair(x, y)));
        }
        sortv(edges);
        vector<bool>vis(edges.size(), 0);
        ll ans = 0;
        for (ll i = 0; i < edges.size(); i++)
        {
            if (ds.getnumofcomponents() == 1)
            {
                break;
            }
            if (!ds.connected(edges[i].second.first, edges[i].second.second))
            {
                vis[i] = 1;
                ds.unify(edges[i].second.first, edges[i].second.second);
                ans += edges[i].first;
            }
        }
        cout << ans << " ";
        // second best
        ll ans2 = INT_MAX;
        for (ll i = 0; i < edges.size(); i++)
        {
            Disjointset ds2(n);
            ll sum = 0;
            if (!vis[i])
            {
                continue;
            }
            for (ll j = 0; j < edges.size(); j++)
            {
                if (j == i)
                {
                    continue;
                }
                if (ds2.getnumofcomponents() == 1)
                {
                    break;
                }
                if (!ds2.connected(edges[j].second.first, edges[j].second.second))
                {
                    ds2.unify(edges[j].second.first, edges[j].second.second);
                    sum += edges[j].first;
                }
            }
            if (ds2.getnumofcomponents() != 1)
            {
                continue;
            }
            ans2 = min(ans2, sum);
        }
        cout << ans2 << endl;
        t--;
    }
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    ll t = 1;
    //    cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
