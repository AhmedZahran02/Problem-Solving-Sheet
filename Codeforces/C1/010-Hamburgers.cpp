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

bool test(ll k, ll Bneeded, ll Sneeded, ll Cneeded, ll Bhave, ll Shave, ll Chave, ll Bprice, ll Sprice, ll Cprice, ll coins) {
    // do logic
    // remove what i already have
    ll Btodo = k * Bneeded - Bhave;
    ll Stodo = k * Sneeded - Shave;
    ll Ctodo = k * Cneeded - Chave;
    // 2 cases todo is negative so no need to buy or todo is positive so need to buy
    ll neededPrice = 0;
    if (Btodo > 0)
    {
        neededPrice += Bprice * Btodo;
    }
    if (Stodo > 0)
    {
        neededPrice += Sprice * Stodo;
    }
    if (Ctodo > 0)
    {
        neededPrice += Cprice * Ctodo;
    }
    if (neededPrice <= coins)
    {
        return true;
    }
    else {
        return false;
    }
}

ll bs(ll start, ll end, ll Bneeded, ll Sneeded, ll Cneeded, ll Bhave, ll Shave, ll Chave, ll Bprice, ll Sprice, ll Cprice, ll coins) {
    while (start < end - 1)
    {
        ll mid = start + (end - start) / 2;
        if (test(mid, Bneeded, Sneeded, Cneeded, Bhave, Shave, Chave, Bprice, Sprice, Cprice, coins))
        {
            start = mid;
        }
        else {
            end = mid - 1;
        }
    }
    if (test(end, Bneeded, Sneeded, Cneeded, Bhave, Shave, Chave, Bprice, Sprice, Cprice, coins))
    {
        return end;
    }
    else
    {
        return start;
    }
    return false;
}

void solve() {
    string s; cin >> s;
    ll Bneeded = 0;
    ll Sneeded = 0;
    ll Cneeded = 0;
    for (ll i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case 'B':
            Bneeded++;
            break;
        case 'S':
            Sneeded++;
            break;
        case 'C':
            Cneeded++;
            break;
        }
    }
    ll Bhave, Shave, Chave; cin >> Bhave >> Shave >> Chave;
    ll Bprice, Sprice, Cprice; cin >> Bprice >> Sprice >> Cprice;
    ll coins; cin >> coins;
    cout << bs(0, 1e14, Bneeded, Sneeded, Cneeded, Bhave, Shave, Chave, Bprice, Sprice, Cprice, coins) << endl;
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
