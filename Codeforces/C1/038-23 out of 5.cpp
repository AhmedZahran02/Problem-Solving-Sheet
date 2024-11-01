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

bool recurse(vector<int>& ar, vector<bool>& vis, int index, int value) {
    if (index == 5 && value == 23) {
        return true;
    }
    bool ans = 0;
    for (int i = 0; i < 5; i++)
    {
        if (!vis[i]) {
            vis[i] = 1;
            if (index == 0) {
                ans |= recurse(ar, vis, index + 1, ar[i]);
            }
            else {
                // case + 
                ans |= recurse(ar, vis, index + 1, value + ar[i]);
                // case *
                ans |= recurse(ar, vis, index + 1, value * ar[i]);
                // case -
                ans |= recurse(ar, vis, index + 1, value - ar[i]);
            }
            vis[i] = 0;
        }
    }
    return ans;
}

void solve() {
    string s;
    while (getline(cin, s) && s != "0 0 0 0 0") {
        stringstream ss(s);
        string word;
        vector<int>ar;
        vector<bool>vis(5,0);
        while (ss >> word) {
            ar.push_back(stoi(word));
        }
        string ans = (recurse(ar, vis, 0, 0)) ? "Possible" : "Impossible";
        cout << ans << endl;
    }
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    int t = 1;
    //cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
