// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<unordered_map>
//#include <chrono>

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
    ll n, m; cin >> n >> m;
    vector<set<ll>>ar(n);
    vector<bool>vis(n,0);
    for (ll i = 0; i < m; i++)
    {
        ll x, y; cin >> x >> y;
        ar[x - 1].insert(y - 1);
        ar[y - 1].insert(x - 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            for (auto j : ar[i])
            {
                if (!vis[j])
                    if (i != j && ar[i].find(j) != ar[i].end())
                    {
                        for (auto val : ar[j])
                        {
                            if (ar[i].size() != ar[j].size() || i != val && ar[i].find(val) == ar[i].end())
                            {
                                cout << "NO" << endl;
                                return;
                            }
                        }
                        vis[j] = 1;
                    }
            }
            vis[i] = 1;
        }
    }
    cout << "YES" << endl;
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


//another sol using dsu

// Made by AOZPROGRAMMING - All Rights Reserved :)

#include<bits/stdc++.h>
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<unordered_map>
//#include <chrono>

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
    ll n, m; cin >> n >> m;
    vector<bool>vis(n, 0);
    Disjointset ds(n);
    for (ll i = 0; i < m; i++)
    {
        ll x, y; cin >> x >> y;
        ds.unify(x - 1, y - 1);
        ds.unify(y - 1, x - 1);
    }
    for (ll i = 0; i < n; i++)
    {
        ll val = ds.find(i);
        if (!vis[val])
        {
            vis[val] = 1;
            if (ds.componentsize(val) != 0 && ds.componentsize(val) != 1 && ds.componentsize(val) * (ds.componentsize(val) - 1) != ds.edgesize(val))
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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

