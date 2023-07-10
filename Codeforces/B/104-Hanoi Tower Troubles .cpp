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

void solve() {
    ll n; cin >> n;
    vector<stack<ll>>ar(n);
    ll i = 1;
    ll cnt = 0;
    while (true)
    {
        bool d = 0;
        for (ll j = 0; j < ar.size(); j++)
        {
            if (!ar[j].empty())
            {
                ll num = ar[j].top() + i;
                if (num == (ll)sqrt(num) * (ll)sqrt(num))
                {
                    ar[j].push(i);
                    d = 1;
                    cnt++;
                    break;
                }
            }
            else {
                ar[j].push(i);
                d = 1;
                cnt++;
                break;
            }
        }
        if (!d)
        {
            break;
        }
        i++;
    }
    cout << cnt << endl;
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
