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
    ll val = t;
    while (t--) {
        ll n; cin >> n;
        Disjointset ds(n);
        vector<pair<ll, ll>>towns(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> towns[i].first >> towns[i].second;
        }
        ll q; cin >> q;
        vector<pair<double, pair<ll, ll>>>edges;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = i + 1; j < n; j++)
            {
                edges.push_back(make_pair(sqrt(pow(abs(towns[i].first - towns[j].first), 2) + pow(abs(towns[i].second - towns[j].second), 2)), make_pair(i, j)));
            }
        }
        sortv(edges);
        for (ll i = 0; i < q; i++)
        {
            ll x, y; cin >> x >> y;
            x--; y--;
            ds.unify(x, y);
        }
        bool d = 0;
        if (t != val - 1) {
            cout << endl;
        }
        for (ll i = 0; i < edges.size(); i++)
        {
            if (!ds.connected(edges[i].second.first, edges[i].second.second))
            {
                ds.unify(edges[i].second.first, edges[i].second.second);
                cout << edges[i].second.first + 1 << " " << edges[i].second.second + 1 << endl;

                d = 1;
            }
        }
        if (!d)
        {
            cout << "No new highways need" << endl;
        }
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
