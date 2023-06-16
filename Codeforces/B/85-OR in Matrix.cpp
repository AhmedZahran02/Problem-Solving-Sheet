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
    ll m, n; cin >> m >> n;
    vector<vector<bool>>in(m, vector<bool>(n, 0));
    vector<vector<bool>>out(m, vector<bool>(n, 0));
    vector<int>row(m, 0);
    vector<int>col(n, 0);
    bool check = 0;
    bool zero = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool x; cin >> x;
            in[i][j] = x;
            if (in[i][j] == 1)
            {
                row[i] += 1;
                col[j] += 1;
                zero = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] == n && col[j] == m)
            {
                out[i][j] = 1;
                check = 1;
            }
            else if (in[i][j] == 1 && !(row[i] == n || col[j] == m)) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    if (!check && !zero)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << out[i][j] << " ";
        }
        cout << endl;
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
