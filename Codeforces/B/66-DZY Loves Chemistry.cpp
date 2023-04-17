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
    int size;
    int* sz;
    int* id;
    int numofcomp;

public:
    Disjointset(int size) {
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

    int componentsizeofnode(int p) {
        return sz[find(p)];
    }

    int componentsize(int i) {
        return sz[i];
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
            sz[root1] = 0;
            id[root1] = root2;
        }
        else {
            sz[root1] += sz[root2];
            sz[root2] = 0;
            id[root2] = root1;
        }
        numofcomp--;
    }
};

void solve() {
    ll n, m; cin >> n >> m;
    Disjointset ds(n);
    for (ll i = 0; i < m; i++)
    {
        ll x, y; cin >> x >> y;
        ds.unify(x - 1, y - 1);
    }
    ll ans = 1;
    for (ll i = 0; i < n; i++)
    {
        if (ds.componentsize(i) > 1)
        {
            ans *= pow(2, ds.componentsize(i) - 1);
        }
    }
    cout << ans << endl;
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
