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

vector<pair<ll, ll>>ans;

void mapdfs(vector<string>& vec, vector<vector<bool>>& vis, ll i, ll j) {
    if (i >= 0 && j >= 0 && i < vec.size() && j < vec[i].size())
    {
        if ((vec[i][j] == ' ' || vec[i][j] == '*') && vis[i][j] == false)
        {
            vis[i][j] = 1;
            ans.push_back({ i,j });
            mapdfs(vec, vis, i + 1, j);
            mapdfs(vec, vis, i - 1, j);
            mapdfs(vec, vis, i, j + 1);
            mapdfs(vec, vis, i, j - 1);
            /* dfs(vec, vis, i + 1, j + 1, n, m);
             dfs(vec, vis, i + 1, j - 1, n, m);
             dfs(vec, vis, i - 1, j + 1, n, m);
             dfs(vec, vis, i - 1, j - 1, n, m);*/
        }
    }
}

void solve() {
    vector<string>ar;
    vector<vector<bool>>vis(31, vector<bool>(80, false));
    string s;
    ll row = 0;
    ll startrow = -1;
    ll startcol = -1;
    while (getline(cin, s) && s[0] != '_')
    {
        if (s.length() == 0)
        {
            continue;
        }
        ar.push_back(s);
        for (ll i = 0; i < s.length(); i++)
        {
            if (s[i] == '*')
            {
                startrow = row;
                startcol = i;
            }
        }
        row++;
    }
    ar.push_back(s);
    mapdfs(ar, vis, startrow, startcol);
    for (ll i = 0; i < ans.size(); i++)
    {
        ar[ans[i].first][ans[i].second] = '#';
    }
    for (ll i = 0; i < ar.size(); i++)
    {
        cout << ar[i] << endl;
    }
    ans.clear();
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    ll t = 1;
    cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
