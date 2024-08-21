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

bool canBlack(int index, vector<vector<ll>>& ar, vector<bool>& color) {
    for (int i = 0; i < ar[index].size(); i++) {
        int item = ar[index][i];
        if (color[item] || item == index) {
            return false;
        }
    }
    return true;
}

vector<ll> ansColor;
vector<ll> activeColor;
void recurse(ll index, vector<vector<ll>>& ar, vector<bool>& color) {
    if (index == ar.size()) {
        if (activeColor.size() > ansColor.size()) ansColor = activeColor;
        return;
    }
    
    recurse(index + 1, ar, color);

    if (canBlack(index,ar,color)) {
        color[index] = 1;
        activeColor.push_back(index);
        recurse(index + 1, ar, color);
        activeColor.pop_back();
        color[index] = 0;
    }
}

void solve() {
    ansColor.clear();
    activeColor.clear();
    ll n, k; cin >> n >> k;
    vector<bool>color(n, 0);
    vector<vector<ll>>ar(n);
    for (ll i = 0; i < k; i++)
    {
        ll x, y; cin >> x >> y;
        x--; y--;
        ar[x].push_back(y);
        ar[y].push_back(x);
    }
    recurse(0, ar,color);
    cout << ansColor.size() << endl;
    for (ll i = 0; i < ansColor.size() - 1; i++)
    {
        cout << ansColor[i]+1 << " ";
    }
    cout << ansColor[ansColor.size()-1] + 1 << endl;
}

int main() {
    fast1();
    fast2();
    //infile();
    //-------------------------------------------
    int t = 1;
    cin >> t;
    while (t)
    {
        solve();
        t--;
    }
    return 0;
}
