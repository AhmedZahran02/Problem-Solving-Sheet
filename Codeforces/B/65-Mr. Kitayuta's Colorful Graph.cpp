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

class disjointset {
private:
    int size;
    int* sz;
    int* id;
    int numofcomp;

public:
    disjointset(int size) {
        if (size > 0)
        {
            this->size = size;
            this->numofcomp = size;
            sz = new int[size];
            id = new int[size];

            for (int i = 0; i < size; i++)
            {
                id[i] = i;
                sz[i] = 1;
            }
        }
        else {
            this->size = 0;
            this->numofcomp = 0;
            sz = new int[0];
            id = new int[0];
        }
    }

    int find(int p) {
        int trav = p;
        while (trav != id[trav])
        {
            trav = id[trav];
        }

        while (p != trav) {
            int next = id[p];
            id[p] = trav;
            p = next;
        }

        return trav;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int componentsize(int p) {
        return sz[find(p)];
    }

    int getsize() {
        return size;
    }

    int getnumofcomponents() {
        return numofcomp;
    }

    void unify(int p, int q) {
        int root1 = find(p);
        int root2 = find(q);

        if (root1 == root2)
        {
            return;
        }

        if (sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            id[root1] = root2;
        }
        else {
            sz[root1] += sz[root2];
            id[root2] = root1;
        }
        numofcomp--;
    }
};

void solve() {
    ll n, m; cin >> n >> m;
    vector<disjointset*>ds(m);
    for (ll i = 0; i < m; i++)
    {
        ds[i] = new disjointset(n);
    }
    for (ll i = 0; i < m; i++)
    {
        ll x, y, c; cin >> x >> y >> c;
        ds[c - 1]->unify(x - 1, y - 1);
    }
    ll q; cin >> q;
    for (ll i = 0; i < q; i++)
    {
        ll x, y; cin >> x >> y;
        ll ans = 0;
        for (ll i = 0; i < m; i++)
        {
            if (ds[i]->connected(x - 1, y - 1))
            {
                ans++;
            }
        }
        cout << ans << endl;
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
