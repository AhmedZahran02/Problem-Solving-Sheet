#include<bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile() freopen("max-pair.in", "r", stdin)
#define sortv(vec) sort(vec.begin(),vec.end()) //sort vector
typedef long long ll;
typedef unsigned long long ull;
const double pi = 3.14159265358979323846;

using namespace std;

//long long int faster pow func
ll fastpow(ll b, ll e) {
    if (!e)
    {
        return 1;
    }
    if (e & 1)
    {
        return b * fastpow(b, e - 1);
    }
    ll x = fastpow(b, e / 2);
    return x * x;
}
//greatest common divisor
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
//least common multiple
long long lcm(int a, int b)
{
    if (a == 1 && b == 1)
    {
        return 1;
    }
    return (a / gcd(a, b)) * b;
}
//factorial
ll factorial(ll n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
//minimum
ll mini(ll a, ll b) {
    if (a >= b) {
        return b;
    }
    else {
        return a;
    }
}
//absolute val
ll posi(ll a) {
    if (a >= 0) {
        return a;
    }
    else {
        ll b = a * (-1);
        return b;
    }
}
// sort by second pair
bool sortbysec(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first > b.first;
}
//Modular multiplicative inverse a=3 m=11 out=4 3*4
int mpow(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a % m) * (x % m)) % m == 1)
            return x;
}
//decimal to binary
string dtb(ll n)
{
    string r;
    while (n != 0) {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}
//powmod
ll PowMod(ll b, ll e, ll M) {
    if (!e)
    {
        return 1;
    }
    ll p = PowMod((b * b) % M, e / 2, M);
    return (e % 2) ? (p * b) % M : p;
}

void solve() {
    int n;
    while (cin >> n && n != 0)
    {
        int nd = 0, s = 0;
        int d2, m2, y2, c2;
        d2 = 0;
        m2 = 0;
        y2 = 0;
        c2 = 0;
        for (int i = 0; i < n; i++)
        {
            int d, m, y, c; int a = 31;
            cin >> d >> m >> y >> c;
            if (m2 == 1 || m2 == 3 || m2 == 5 || m2 == 7 || m2 == 8 || m2 == 10 || m2 == 12)
            {
                a = 31;
            }
            else if (m2 == 4 || m2 == 6 || m2 == 9 || m2 == 11)
            {
                a = 30;
            }
            else if (m2 == 2)
            {
                if ((y % 4 == 0 && y % 100 != 0) || (y % 4 == 0 && y % 100 != 0 && y % 400 == 0))
                {
                    a = 29;
                }
                else
                {
                    a = 28;
                }
            }
            a++;

            int x2 = (m2 + 1) % 13;
            if (x2 == 0)
            {
                x2++;
            }
            int x = (d2 + 1) % a;
            if (x == 0)
            {
                x++;
            }
            if (y == y2 || (y == y2 + 1 && m2 == 12))
            {

                if (m == m2 || (m == x2 && (d2 == a-1)))
                {
                    if (d == x)
                    {
                        s += c - c2;
                        nd++;
                    }
                }

            }
            d2 = d; m2 = m; y2 = y; c2 = c;
        }
        cout << nd << " " << s << endl;
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