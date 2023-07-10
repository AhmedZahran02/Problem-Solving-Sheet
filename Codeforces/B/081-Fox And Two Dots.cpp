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

bool done = 0;

void mapdfs(vector<vector<char>>& vec, vector<vector<bool>>& vis, int i, int j, int n, int m, char x, int depth, int iold, int jold) {
    if (i >= 0 && j >= 0 && i < n && j < m)
    {
        if (vec[i][j] == x && vis[i][j] == false)
        {
            vis[i][j] = 1;
            if (!(i + 1 == iold && j == jold))
                mapdfs(vec, vis, i + 1, j, n, m, x, depth + 1, i, j);
            if (!(i - 1 == iold && j == jold))
                mapdfs(vec, vis, i - 1, j, n, m, x, depth + 1, i, j);
            if (!(i == iold && j + 1 == jold))
                mapdfs(vec, vis, i, j + 1, n, m, x, depth + 1, i, j);
            if (!(i == iold && j - 1 == jold))
                mapdfs(vec, vis, i, j - 1, n, m, x, depth + 1, i, j);
        }
        else if (vec[i][j] == x && vis[i][j] == true && depth >= 4)
        {
            done = 1;
        }
    }
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<char>>in(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> in[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mapdfs(in, vis, i, j, n, m, in[i][j], 0, 0, 0);
            if (done)
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
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
