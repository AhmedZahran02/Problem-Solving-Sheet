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

//greatest common divisor
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    double a, b, c, d; cin >> a >> b >> c >> d;
    double ratio = 1;
    if (a * d < b * c) //need a lot of horizontal space
    {
        ratio = (double)a / c;
        c = a;
        d = d * ratio;
    }
    else //need a lot of vertical space 
    {
        ratio = (double)b / d;
        c = c * ratio;
        d = b;
    }
    ll num = round(c * d / ratio);
    ll dum = round(a * b / ratio);
    ll Gcd = gcd(num, dum);
    num /= Gcd;
    dum /= Gcd;
    cout << dum - num << "/" << dum << endl;
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
