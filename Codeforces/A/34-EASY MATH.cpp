
// this solution hasnot got accepted yet it is solid base for inclusion and exclusion principle
// we havenot found the problem in it yet


#include<bits/stdc++.h>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile() freopen("max-pair.in", "r", stdin)
#define sortv(vec) sort(vec.begin(),vec.end()) //sort vector
typedef long long ull;
typedef unsigned long long ll;
const double pi = 3.14159265358979323846;

using namespace std;

//long long int faster pow func
ull fastpow(ull b, ull e) {
    if (!e)
    {
        return 1;
    }
    if (e & 1)
    {
        return b * fastpow(b, e - 1);
    }
    ull x = fastpow(b, e / 2);
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
ull factorial(ull n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
//minimum
ull mini(ull a, ull b) {
    if (a >= b) {
        return b;
    }
    else {
        return a;
    }
}
//absolute val
ull posi(ull a) {
    if (a >= 0) {
        return a;
    }
    else {
        ull b = a * (-1);
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
string dtb(ull n)
{
    string r;
    while (n != 0) {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}
//powmod
ull PowMod(ull b, ull e, ull M) {
    if (!e)
    {
        return 1;
    }
    ull p = PowMod((b * b) % M, e / 2, M);
    return (e % 2) ? (p * b) % M : p;
}

void solve() {
    ull n; ull m, a, d;
    cin >> n >> m >> a >> d;
    if (a>m)
    {
        if (n<=0)
        {
            
            if (m==n)
            {
                if (m==0)
                {
                    cout << 0 << endl;
                    return;
                }
                cout << 1 << endl;
            }
            else
            {
                cout << m - n << endl;;
            }
        }
        else
        {
        cout << m - n + 1 << endl;
        }
        return;
    }
    ull n1 = m / a + 1;
    ull n2 = m / (a + d) + 1;
    ull n3 = m / (a + 2 * d) + 1;
    ull n4 = m / (a + 3 * d) + 1;
    ull n5 = m / (a + 4 * d) + 1;

    ull n11 = max(n, 0LL) / a + 1;
    ull n22 = max(n, 0LL) / (a + d) + 1;
    ull n33 = max(n, 0LL) / (a + 2 * d) + 1;
    ull n44 = max(n, 0LL) / (a + 3 * d) + 1;
    ull n55 = max(n, 0LL) / (a + 4 * d) + 1;

    ull n1n2 = m / lcm((a + d), (a)) + 1;
    ull n1n3 = m / lcm((a + 2 * d), (a)) + 1;
    ull n1n4 = m / lcm((a + 3 * d), (a)) + 1;
    ull n1n5 = m / lcm((a + 4 * d), (a)) + 1;
    ull n2n3 = m / lcm((a + 2 * d), (a + d)) + 1;
    ull n2n4 = m / lcm((a + 3 * d), (a + d)) + 1;
    ull n2n5 = m / lcm((a + 4 * d), (a + d)) + 1;
    ull n3n4 = m / lcm((a + 3 * d), (a + 2 * d)) + 1;
    ull n3n5 = m / lcm((a + 4 * d), (a + 2 * d)) + 1;
    ull n4n5 = m / lcm((a + 4 * d), (a + 3 * d)) + 1;

    ull n1n22 = max(n, 0LL) / lcm((a + d), (a)) + 1;
    ull n1n32 = max(n, 0LL) / lcm((a + 2 * d), (a)) + 1;
    ull n1n42 = max(n, 0LL) / lcm((a + 3 * d), (a)) + 1;
    ull n1n52 = max(n, 0LL) / lcm((a + 4 * d), (a)) + 1;
    ull n2n32 = max(n, 0LL) / lcm((a + 2 * d), (a + d)) + 1;
    ull n2n42 = max(n, 0LL) / lcm((a + 3 * d), (a + d)) + 1;
    ull n2n52 = max(n, 0LL) / lcm((a + 4 * d), (a + d)) + 1;
    ull n3n42 = max(n, 0LL) / lcm((a + 3 * d), (a + 2 * d)) + 1;
    ull n3n52 = max(n, 0LL) / lcm((a + 4 * d), (a + 2 * d)) + 1;
    ull n4n52 = max(n, 0LL) / lcm((a + 4 * d), (a + 3 * d)) + 1;

    ull n1n2n3 = m / lcm(a + 2 * d, lcm(a + d, a)) + 1;
    ull n1n2n4 = m / lcm((a + 3 * d), lcm(a + d, a)) + 1;
    ull n1n2n5 = m / lcm((a + 4 * d), lcm(a + d, a)) + 1;
    ull n1n3n4 = m / lcm((a + 3 * d), lcm(a + 2 * d, a)) + 1;
    ull n1n3n5 = m / lcm((a + 4 * d), lcm(a + 2 * d, a)) + 1;
    ull n1n4n5 = m / lcm((a + 4 * d), lcm((a + 3 * d), a)) + 1;
    ull n2n3n4 = m / lcm((a + 3 * d), lcm(a + 2 * d, a + d)) + 1;
    ull n2n3n5 = m / lcm((a + 4 * d), lcm(a + 2 * d, a + d)) + 1;
    ull n2n4n5 = m / lcm((a + 4 * d), lcm((a + 3 * d), a + d)) + 1;
    ull n3n4n5 = m / lcm((a + 4 * d), lcm((a + 3 * d), a + 2 * d)) + 1;

    ull n1n2n32 = max(n, 0LL) / lcm(a + 2 * d, lcm(a + d, a)) + 1;
    ull n1n2n42 = max(n, 0LL) / lcm((a + 3 * d), lcm(a + d, a)) + 1;
    ull n1n2n52 = max(n, 0LL) / lcm((a + 4 * d), lcm(a + d, a)) + 1;
    ull n1n3n42 = max(n, 0LL) / lcm((a + 3 * d), lcm(a + 2 * d, a)) + 1;
    ull n1n3n52 = max(n, 0LL) / lcm((a + 4 * d), lcm(a + 2 * d, a)) + 1;
    ull n1n4n52 = max(n, 0LL) / lcm((a + 4 * d), lcm((a + 3 * d), a)) + 1;
    ull n2n3n42 = max(n, 0LL) / lcm((a + 3 * d), lcm(a + 2 * d, a + d)) + 1;
    ull n2n3n52 = max(n, 0LL) / lcm((a + 4 * d), lcm(a + 2 * d, a + d)) + 1;
    ull n2n4n52 = max(n, 0LL) / lcm((a + 4 * d), lcm((a + 3 * d), a + d)) + 1;
    ull n3n4n52 = max(n, 0LL) / lcm((a + 4 * d), lcm((a + 3 * d), a + 2 * d)) + 1;

    ull n1n2n3n4 = m / lcm((a + 3 * d), lcm(a + 2 * d, lcm(a + d, a))) + 1;
    ull n1n2n3n5 = m / lcm((a + 4 * d), lcm(a + 2 * d, lcm(a + d, a))) + 1;
    ull n1n2n4n5 = m / lcm((a + 4 * d), lcm((a + 3 * d), lcm(a + d, a))) + 1;
    ull n1n3n4n5 = m / lcm((a + 4 * d), lcm((a + 3 * d), lcm(a + 2 * d, a))) + 1;
    ull n2n3n4n5 = m / lcm((a + 4 * d), lcm((a + 3 * d), lcm(a + 2 * d, a + d))) + 1;

    ull n1n2n3n42 = max(n, 0LL) / lcm((a + 3 * d), lcm(a + 2 * d, lcm(a + d, a))) + 1;
    ull n1n2n3n52 = max(n, 0LL) / lcm((a + 4 * d), lcm(a + 2 * d, lcm(a + d, a))) + 1;
    ull n1n2n4n52 = max(n, 0LL) / lcm((a + 4 * d), lcm((a + 3 * d), lcm(a + d, a))) + 1;
    ull n1n3n4n52 = max(n, 0LL) / lcm((a + 4 * d), lcm((a + 3 * d), lcm(a + 2 * d, a))) + 1;
    ull n2n3n4n52 = max(n, 0LL) / lcm((a + 4 * d), lcm((a + 3 * d), lcm(a + 2 * d, a + d))) + 1;

    ull n1n2n3n4n5 = m / lcm((a + 4 * d), lcm((a + 3 * d), lcm(a + 2 * d, lcm(a + d, a)))) + 1;

    ull n1n2n3n4n52 = max(n, 0LL) / lcm((a + 4 * d), lcm((a + 3 * d), lcm(a + 2 * d, lcm(a + d, a)))) + 1;

    ull x = m - n 
            - ((n1 - n11 + n2 - n22 + n3 - n33 + n4 - n44 + n5 - n55) 
            - 1 * (n1n2 + n1n3 + n1n4 + n1n5 + n2n3 + n2n4 + n2n5 + n3n4 + n3n5 + n4n5 - (n1n22 + n1n32 + n1n42 + n1n52 + n2n32 + n2n42 + n2n52 + n3n42 + n3n52 + n4n52)) 
            + 1 * (n1n2n3n4n5 - n1n2n3n4n52) 
            + 1 * (n1n2n3 + n1n2n4 + n1n2n5 + n1n3n4 + n1n3n5 + n1n4n5 + n2n3n4 + n2n3n5 + n2n4n5 + n3n4n5 - (n1n2n32 + n1n2n42 + n1n2n52 + n1n3n42 + n1n3n52 + n1n4n52 + n2n3n42 + n2n3n52 + n2n4n52 + n3n4n52)) 
            - 1 * (n1n2n3n4 + n1n2n3n5 + n1n2n4n5 + n1n3n4n5 + n2n3n4n5 - (n1n2n3n42 + n1n2n3n52 + n1n2n4n52 + n1n3n4n52 + n2n3n4n52)));
    if (n != -1)
    {
        x++;
    }
    if (n%a==0|| n % (a+d) == 0 || n % (a + 2*d) == 0 || n % (a + 3*d) == 0 || n % (a + 4*d) == 0)
    {
        x--;
    }
    if (n==m && n==-1)
    {
        x++;
    }
    if (a == 1)
    {
        x = 0;
    }
    
    cout << x << endl;
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