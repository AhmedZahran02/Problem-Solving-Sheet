#include<bits/stdc++.h>
#include<unordered_map>
//#include <iostream>
//#include<string>

#define fast1() ios_base::sync_with_stdio(false)
#define fast2() cin.tie(NULL)
#define infile() freopen("max-pair.in", "r", stdin)
#define sortv(vec) sort(vec.begin(),vec.end()) //sort vector
typedef long long ll;
const double pi = 3.14159265358979323846;

using namespace std;

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
//int mpow(int a, int m) 
//{
//    for (int x = 1; x < m; x++)
//        if (((a % m) * (x % m)) % m == 1)
//            return x;
//}
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

int main() {
    fast1();
    fast2();
    //infile();
    //------------------------------------------- 
    int n, m;
    int cnt = 0;
    cin >> n >> m;
    while (n<=m)
    {
        n *= 3;
        m *= 2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}